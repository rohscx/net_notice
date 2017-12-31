// functions
// network status notification
int notice (int a) {
	//printf("int a = %i\n", a); //debug
	if (a <= 0){
		char status_1[] = {"(ノ ˘_˘)ノ　ζ|||ζ　ζ|||ζ　ζ|||ζ"};
		printf ("NETWORK STATUS : %s\n" , status_1);
		return 10;
	}else {
		char status_1[] = {"⊃｡•́‿•̀｡)⊃━✿✿✿✿✿✿✿✿✿✿✿✿✿✿✿✿✿✿"};
		printf ("NETWORK STATUS : %s\n" , status_1);
		return 10;
	}

}
