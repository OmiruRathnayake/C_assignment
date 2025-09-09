// Game loop
	int gameOver = GAMEOVER;
	int round = 1;
	
	printf("\n=== GAME STARTS ===\n");
	
	while (!gameOver) {
		printf("\n--- Round %d ---\n", round);
		
		// Loop through each player
		for (int playerName = 0; playerName < MAX_PLAYERS; playerName++) {
			char playerChar = (playerName == A) ? 'A' : (playerName == B) ? 'B' : 'C';
			
			//roll the dice
			int movementRoll = movementDice();
			players[playerName].throwCount ++;

			//to enter the game
			if (isInStandingArea(&players) && isPlayerEntersGame(&players, isInStandingArea(&players), playerName, movementRoll))
			{
				printf("\n");
			}
			else
			{
				printf("\n");
			}
			

			
		}

		gameOver = !GAMEOVER;
		
		// prevent infinite loops (optional safety) (for testing purposes)
		//if (round > 1000) {
		//	printf("Game ended after 1000 rounds - no winner!\n");
		//	break;
		//}

		printf("\n");
		printf("Player A[%d,%d,%d]: %d movement points\n", players[A].currentFloor, players[A].currentWidth, players[A].currentLength,players[A].score);
		printf("Player B[%d,%d,%d]: %d movement points\n", players[B].currentFloor, players[B].currentWidth, players[B].currentLength,players[B].score);
		printf("Player C[%d,%d,%d]: %d movement points\n", players[C].currentFloor, players[C].currentWidth, players[C].currentLength,players[C].score);

		if (gameOver) break;
		round++;
	}
	
	printf("\nFinal Scores:\n");
	printf("Player A: %d movement points\n", players[A].score);
	printf("Player B: %d movement points\n", players[B].score);
	printf("Player C: %d movement points\n", players[C].score);

