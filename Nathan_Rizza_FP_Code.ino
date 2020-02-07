//Nathan Rizza
//Final Project Electronics


int wins=0; // Global variable that counts how many wins per game you have.


void setup()
{

  for(int i=2;i<12;i++)//Sets pins 2-11 as outputs.
  {
  pinMode(i,OUTPUT);
  }

  pinMode(13,INPUT_PULLUP);//Sets pin 13 as an Input with a pullup resistor.
  
}


void loop() 
{
  
  int diff = 6;//World Record Diff: Brandon Reno with a diff of 7

  if(wins==0)
  {
  backAndForth(2000/diff); // Level 1
  }
   if(wins==1)
  {
  backAndForth(1000/diff); // Level 2
  }
   if(wins==2)
  {
  backAndForth(500/diff); // Level 3
  }
   if(wins>=3)
  {
   winnerDance();	// If the user gets 3 wins they win the game and get a dance.
   wins=0; 			// This resets the game.
  }
  updateScore();	//Updates the game LED's that count the score.
}


//Given: blinkSpeed- The number of miliseconds between game light changes.
//Action: Will go through the game lights back and forth checking with every light change if the user has clicked the button.
//If the user does click the button, the user will either win (if i=5) of lose (i!=5). if the button is not pushed nothing happens.
void backAndForth(int blinkSpeed)
{
  int Event =0;
  
	for(int i=2;i<9;i++)//Going forward
	{
  
      
		digitalWrite(i,HIGH);//Light is turned on
       
       for(int j=0;j<blinkSpeed;j++)
       {
        delay(1);
        
        if((digitalRead(13)==LOW)&&(i!=5))//Check if the user loses. Button + i!=5
         {
		  loser();
          Event=1;
          updateScore();
          delay(5000);     
		 }
	   
	   if((digitalRead(13)==LOW)&&(i==5))//Check if the user wins. Button + i=5
        {
	    digitalWrite(5,LOW);
        wins++;
		Event=1;
        updateScore();
        delay(5000);
	    }
	   
		if(Event>0)
          {
          break;
          }
	  }
          digitalWrite(i,LOW);
        }
	
	if(Event==0)
	{

  
  
        for(int i=7;i>2;i--)//going backwards
	{
		      
      digitalWrite(i,HIGH);//Light is turned on
       
       for(int j=0;j<blinkSpeed;j++)
       {
        delay(1);
        
         if((digitalRead(13)==LOW)&&(i!=5))//Check if the user loses. Button + i!=5
         {
	    loser();
           Event=1;
           updateScore();
           delay(5000);
	   }
	   
	   if((digitalRead(13)==LOW)&&(i==5))//Check if the user wins. Button + i=5
           {
	    digitalWrite(5,LOW);
            wins++;
			Event=1;
            updateScore();
            delay(5000);
	   }
	   
           if(Event>0)
             {
            break;
             }
	  }
          digitalWrite(i,LOW);
	}
      }      
  
  
	if(wins>3)//Makes sure that the wins doesn't excced 3
	{
	wins=3;
	}

}


void loser()//Plays an animation and sets the wins back to 0 resetting the game.
{
    for(int i=2;i<9;i++)//Clear game LED's
	{
        digitalWrite(i,LOW);
        }
  
    digitalWrite(11,HIGH);
    
    delay(500);

    digitalWrite(10,HIGH);
    
    delay(500);
    
    digitalWrite(9,HIGH);
    
    delay(500);
	  
	digitalWrite(11,LOW);
    
    delay(500);

    digitalWrite(10,LOW);
    
    delay(500);
    
    digitalWrite(9,LOW);
	
      wins=0;
}


void updateScore() //Updates the score LED's
{
      for(int i=2;i<9;i++)//Clear game LED's
	{
        digitalWrite(i,LOW);
        }
        
   if(wins==0)
  {
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }

   if(wins==1)
  {
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
   if(wins==2)
  {
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
  }
     if(wins>=3)
  {
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
  }
  
}


void winnerDance() //Sweet Victory animation
{
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    
    delay(500);
    
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    
    delay(500);
    
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    
    delay(500);
   
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    
    delay(500);
    
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    
}
