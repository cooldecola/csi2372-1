bool QwixxScoreSheet::score(RollOfDice &rd, Colour colour_ss, int pos){
	std::string colour_ss;
	RollOfDice* row_ss;
	int position = 0;

	if (c == red){
		position = int(rd) - 2;
		colour_ss = "red";
		row_ss = redRow.values;
	} else if (c == yellow){
		position = int(rd) - 2;
		colour_ss = "yellow";
		row_ss = yellowRow.values;
	} else if (c = green){
		position = 12 - int(rd)
		colour_ss = "green";
		row_ss = greenRow.values;
	} else{
		position = 12 - int(rd);
		colour_ss = "blue";
		row_ss = blueRow.values;
	}

	//To test if the proper game_dices have been selected
	if ((rd.game_dices[0].colourOfDice == c) || (rd.game_dices[1].colourOfDice == c)){
		if (((rd.game_dices[0]) == c) && (rd.game_dices[1] == Colour::white) || ((rd.game_dices[1]) == c) && (rd.game_dices[0] == Colour::white)){
			return true;
		}
		std::cout << "The selection of Dices isn't correct";
		return false;
	}

	// This fucntion runs through the entire row and checks up till an X is marked off by user, if it does encounter one, returns false
	while (i < 11){
		if (row[i].game_dices.size() != 0){
			if (position < i){
				std::cout << "You cannot put an X to the left of any X";
				i++;
			}
		}
		return false;
	}


	// To check if the row is unlocked.
	if(int(row[11]) != 0){
		std::cout << "This is a locked row" << endl;
		return false;
	}

	// Passed dice is to be scored in a scored cell
	if(int(row[position]) != 0){
		cout << "This position is taken" << endl;
		return false;
	}


// The overloaded insertion operator

ostream& QwixxScoreSheet::operator<<(ostream& os){

	os << redRow;
	os << yellowRow;
	os << greenRow;
	os << blueRow;

	os << "\t----------------------------------------------------------- ";

//Displaying the number of failed turns
	if (numFail > 0)
		os << "Penalty Numbers: ";
		for(int i = 0; i < numFail.size(); ++i){
			os << int(numFail[i]) << endl;
		}
	}
	return os;
}


int QwixxScoreSheet::calcTotal(){
	int total = 0;

	// Counts the Red score
	for(int i = 0; i < 12; i++){
		if(int(redRow[i]) != 0){
			total += redRow[i];
		}
	}

	//Counts the Yellow score
	for(int i = 0; i < 12; ++i){
		if(int(yellowRow[i]) != 0){
			total += yellowRow[i];
		}
	}

	//Counts the Green score
	for(int i=0; i<12; ++i){
		if(int(greenRow[i]) != 0){
			total += greenRow[i];
		}
	}

	//Counts the blue score
	for(int i=0; i<12; ++i){
		if(int(blueRow[i]) != 0){
			total += blueRow[i];
		}
	}

	// Failed attempts
	total -= (numFail.size()*5);

	return total;
}


int QwixxScoreSheet::setTotal(){

	int total = calcTotal();
	this->totalScore = total;
	return total;
}
// WAS NOT ABLE TO FINISH THE CLASS

}
