template <template T, Colour c>
ostream& QwintoRow<c>::operator<< (ostream& os){
  if (c == red || c == yellow){
    os << "\t------------------------------------";
    if (c == red){
      os <<"Red:\t";
    }
    os <<"Yellow:\t";

    for (int i = 0; i < 12; i++){
      if (scoreList[0]==0){
        if (i < 8){
          os << "| " << i+2;
        }

        if (i > 7){
          os << "|" << i+10;
        }

        if (i == 11){
          lockChecker = false;
          os << "| U";
        }
      }
      else
      os << "XX";
      if (i == 11){
        lockChecker - true;
        os << "| L";
      }
    }
    os << "\t------------------------------------";
  }

  if (c == green || c == blue){
    os << "\t------------------------------------";
    if (c == green){
      os <<"Green:\t";
    }
    os << "Blue:\t";

    for (int i = 12; i > 0; i--){
      if (scoreList[0] == 0){
        if (i > 9){
          os << "|" << i;
        }

        if (i < 10){
          os << "| " << i;
        }
      }

      else
      os << "XX";
      if (i == 11){
        os << "| L";
      }
    }
    os << "\t------------------------------------";
  }
}

template <template T, Colour c>
RollofDice& QwintoRow<c>::operator+= (RollOfDice rd){
  std::string colour_ss;
  int position;
  RollOfDice row_ss;

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
//WAS NOT ABLE TO FINISH THE CLASS
}
