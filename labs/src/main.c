/*
 *	A program to demonstrate simple graphical operations
 */

/*  This line allows the compiler to understand the
 *	graphics functions
 */
 #include <graphics_lib.h>
 int draw_stickman(user_x,user_y,colour)
 {

    GFX_InitWindow(2000,1000); // bring up the window

    switch (colour)
    {
        case 1:
            GFX_SetColour(GREEN);
            break;
        case 2:
            GFX_SetColour(YELLOW);
            break;
        case 3:
            GFX_SetColour(WHITE);
            break;

    }

    GFX_MoveTo(user_x,user_y);
    GFX_DrawLineTo(user_x + 10, user_y - 30, 5);//left leg
    GFX_MoveTo(user_x + 20,user_y);
    GFX_DrawLineTo(user_x + 10, user_y - 30, 5);//right leg
    GFX_MoveTo(user_x + 10, user_y - 30);
    GFX_DrawLineTo(user_x + 10, user_y - 60, 5);//body
    GFX_MoveTo(user_x + 10, user_y - 50);
    GFX_DrawLineTo(user_x - 10, user_y - 50, 5);//left arm
    GFX_MoveTo(user_x + 10, user_y - 50);
    GFX_DrawLineTo(user_x + 30, user_y - 50, 5);//right arm
    //
    GFX_DrawCircle(user_x + 10, user_y - 70, 10, 5);//head

    GFX_UpdateDisplay();


    return 0;

 }

int main(void)
{
    int user_x;
    int user_y;
    int user_colour;
    int user_angle;
    int user_power;
    int colour;
    /* Set Projectile Variables */
    float time;
    float pos_x;
    float pos_y;
    float initial_pos_x;
    float initial_pos_y;
    int distance;
/*====================================================
====================  User Input  ======================*/
    printf("\n\nPlease enter a value for x\n");
    scanf("%d", &user_x);
    printf("\n\nPlease enter a value for y\n");
    scanf("%d", &user_y);

    printf("\nPlease Select a colour:");
    printf("\n1. Green\n2. Yellow\n3. White\n\n");
    scanf("%d" , &user_colour);

    printf("\n\nPlease enter an angle (as an integer) to throw the projectile \n");
    printf("Hint: You can throw it further at a lower angle\n\n");
    scanf("%d", &user_angle);
/*,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,*/

    if (user_angle < 1)
    {
        printf("You can't throw the projectlie at that angle\n");
        printf("Try an integer between 1 and 89\n\n");
        GFX_PauseFor(3000);
        GFX_CloseWindow();
        return 0;
    }
    else if (user_angle > 89)
    {
        printf("\n\nYou can't throw the projectlie at that angle\n");
        printf("Try an integer between 1 and 89\n\n");
        GFX_PauseFor(5000);
        GFX_CloseWindow();
        return 0;
    }

/*,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,*/

    printf("\nPlease enter a power (as an integer) for how hard you throw the projectile\n\n");
    scanf("%d", &user_power);
/*,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,*/

    if (user_power < 1)
    {
        printf("You can't throw the projectlie with that power\n");
        printf("Try an integer between 1 and 100\n\n");
        GFX_PauseFor(5000);
        GFX_CloseWindow();
        return 0;
    }
    else if (user_power > 100)
    {
        printf("You can't throw the projectlie with that power\n");
        printf("Try an integer between 1 and 100\n\n");
        GFX_PauseFor(5000);
        GFX_CloseWindow();
        return 0;
    }


/*,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,*/
/*=============================================================================*/

    //--------------------------
    float vel_x = (100/user_angle) + 10;              // Let's the user adjust the angle to throw at,,
    float vel_y = user_power;                      // Stays constant, acts as a reference,,
    float gravity = 10;
    //---------------------------------
    switch (user_colour)
    {
        case 1:
            /* Make the colour Green */
            colour = 1;
            break;
        case 2:
            /* Make the colour Yellow */
            colour = 2;
            break;
        case 3:
            /* Make the colour White */
            colour = 3;
            break;

    }

    draw_stickman(user_x,user_y,colour);
//---------------------------------------------------------------------------------------

    //GFX_MoveTo(initial_pos_x, initial_pos_y);
    GFX_MoveTo(user_x+ 30,user_y - 50);
    pos_x = user_x + 30; // sets the initial x position to be the hand
    GFX_SetColour(RED);
    do{
        /* Draw the path of the projectile */
        time = (pos_x - (user_x + 30))/ vel_x;
        pos_y = (user_y - 50) - (vel_y * time) + (gravity * time * time)/2;
        GFX_DrawLineTo(pos_x, pos_y,3);
        pos_x += 1;
        pos_y += 1;
        GFX_UpdateDisplay();

    } while (user_y > pos_y);

    distance = (pos_x - user_x) * 0.03;  /// works out the distance thrown
    printf("\n\nYou threw the projectile a total distance of %d meters\n\n", distance); // print distance

    /* move the contents of the screen buffer to the display */
    GFX_UpdateDisplay();

	/* Wait for a user's signal to exit*/
	getchar();
	printf("\n\nPlease press enter");
    getchar();

    /* remove the display */
    GFX_CloseWindow();


    return 0;
}


