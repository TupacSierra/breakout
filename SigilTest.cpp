#include <sl.h>


using namespace std;

int main()
{
  

    const int width = 640;
    const int height = 480;

    slWindow(width, height, "TestBreakout", 0);


    int paddleX = 300;
    int paddleY = 10;
    int paddleWidth = 140;
    int paddleHeight = 10;
    int paddleSpeed = 5;

    
    int ballX = 320;
    int ballY = 240;
    int ballSize = 10;
    int ballSpeedX = 2;
    int ballSpeedY = 2;

   
    while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
    {
        
        if (slGetKey(SL_KEY_LEFT)) {
            paddleX -= paddleSpeed;
        }
        if (slGetKey(SL_KEY_RIGHT)) {
            paddleX += paddleSpeed;
        }

      
        ballX += ballSpeedX;
        ballY += ballSpeedY;

       


        if (ballX >= paddleX && ballX <= paddleX + paddleWidth  &&
            ballY >= paddleY && ballY <= paddleY + paddleHeight)
        {  
            ballSpeedY = -ballSpeedY;
        }



       
        if (ballX <= ballSize || ballX >= width - ballSize) {
            ballSpeedX = -ballSpeedX;
        }

        if (ballY <= ballSize|| ballY >= height - ballSize) {
            ballSpeedY = -ballSpeedY;
        }
 

        slRectangleFill(paddleX, paddleY, paddleWidth, paddleHeight);
        
        slCircleFill(ballX, ballY, ballSize,15);

       
        slRender();
       
    }

    
    slClose();

    return 0;
}