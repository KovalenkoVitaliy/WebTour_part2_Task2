Action()
{ 
	int cost = TRUE;
	int requiredcost=0;
	int requiredindex;
	int mas[4];
	int i;
	char* z;
	char* typeseat;
	char* ArriveCity;
	char* masout[4];
	
	web_reg_save_param_ex(
		"ParamName=SeatingPref",
		"LB=seatPref\" value=\"",
		"RB=\"",
		"Ordinal={Random1}",
		SEARCH_FILTERS,
		LAST);
	
	while (cost) {
	
		web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
		web_reg_save_param_ex(
		"ParamName=CostticketOut1",
		"LB=;",
		"RB=;{DepartDate}\"",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	
		web_reg_save_param_ex(
		"ParamName=CostticketOut2",
		"LB=;",
		"RB=;{DepartDate}\"",
		"Ordinal=2",
		SEARCH_FILTERS,
		LAST);
		
		web_reg_save_param_ex(
		"ParamName=CostticketOut3",
		"LB=;",
		"RB=;{DepartDate}\"",
		"Ordinal=3",
		SEARCH_FILTERS,
		LAST);
	
		web_reg_save_param_ex(
		"ParamName=CostticketOut4",
		"LB=;",
		"RB=;{DepartDate}\"",
		"Ordinal=4",
		SEARCH_FILTERS,
		LAST);
		
		web_reg_save_param_ex(
		"ParamName=OutBoundFlight1",
		"LB=\"outboundFlight\" value=\"",
		"RB=\"",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
		
		web_reg_save_param_ex(
		"ParamName=OutBoundFlight2",
		"LB=\"outboundFlight\" value=\"",
		"RB=\"",
		"Ordinal=2",
		SEARCH_FILTERS,
		LAST);
		
		web_reg_save_param_ex(
		"ParamName=OutBoundFlight3",
		"LB=\"outboundFlight\" value=\"",
		"RB=\"",
		"Ordinal=3",
		SEARCH_FILTERS,
		LAST);
		
		web_reg_save_param_ex(
		"ParamName=OutBoundFlight4",
		"LB=\"outboundFlight\" value=\"",
		"RB=\"",
		"Ordinal=4",
		SEARCH_FILTERS,
		LAST);

		web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={HomeCity}", ENDITEM, 
		"Name=departDate", "Value={DepartDate}", ENDITEM, 
		"Name=arrive", "Value={ArriveCity1}", ENDITEM, 
		"Name=returnDate", "Value={ReturnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={SeatingPref}", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=52", ENDITEM, 
		"Name=findFlights.y", "Value=3", ENDITEM, 
		LAST);
		
		lr_output_message("Cost1 of ticket is: %s",lr_eval_string("{CostticketOut1}"));
		lr_output_message("Cost2 of ticket is: %s",lr_eval_string("{CostticketOut2}"));
		lr_output_message("Cost3 of ticket is: %s",lr_eval_string("{CostticketOut3}"));
		lr_output_message("Cost4 of ticket is: %s",lr_eval_string("{CostticketOut4}"));
		lr_output_message("");
			
		z = lr_eval_string("{CostticketOut1}");
		mas[0] = atoi(z);
		z = lr_eval_string("{CostticketOut2}");
		mas[1] = atoi(z);
		z = lr_eval_string("{CostticketOut3}");
		mas[2] = atoi(z);
		z = lr_eval_string("{CostticketOut4}");
		mas[3] = atoi(z);
		
		masout[0] = lr_eval_string("{OutBoundFlight1}");
		masout[1] = lr_eval_string("{OutBoundFlight2}");
		masout[2] = lr_eval_string("{OutBoundFlight3}");
		masout[3] = lr_eval_string("{OutBoundFlight4}");
		
		for (i = 0; i < 4; i++) {
			if (mas[i] > 200 && mas[i] < 400) {
				
				requiredcost = mas[i];
				requiredindex = i;
				lr_save_int(requiredcost, "REQUIREDCOST");
				lr_save_int(requiredindex, "REQUIREDINDEX");
				lr_output_message("Required cost of ticket is: %s",lr_eval_string("{REQUIREDCOST}"));
				lr_output_message("Index of required cost of ticket is: %s",lr_eval_string("{REQUIREDINDEX}"));
				lr_save_string(masout[requiredindex], "OutBoundFlight");
				lr_output_message("Required OutBoundFlight is: %s",lr_eval_string("{OutBoundFlight}"));
				lr_output_message("Date of flight is: %s",lr_eval_string("{DepartDate}"));
				lr_output_message("Arrive city is: %s",lr_eval_string("{ArriveCity1}"));
				lr_output_message("Type of Seat is First");
				cost = FALSE;
				break;
			}
		
		}
		
		while (cost) {
			
				web_reg_save_param_ex(
				"ParamName=CostticketOut1",
				"LB=;",
				"RB=;{DepartDate}\"",
				"Ordinal=1",
				SEARCH_FILTERS,
				LAST);
	
				web_reg_save_param_ex(
				"ParamName=CostticketOut2",
				"LB=;",
				"RB=;{DepartDate}\"",
				"Ordinal=2",
				SEARCH_FILTERS,
				LAST);
		
				web_reg_save_param_ex(
				"ParamName=CostticketOut3",
				"LB=;",
				"RB=;{DepartDate}\"",
				"Ordinal=3",
				SEARCH_FILTERS,
				LAST);
	
				web_reg_save_param_ex(
				"ParamName=CostticketOut4",
				"LB=;",
				"RB=;{DepartDate}\"",
				"Ordinal=4",
				SEARCH_FILTERS,
				LAST);
		
				web_reg_save_param_ex(
				"ParamName=OutBoundFlight1",
				"LB=\"outboundFlight\" value=\"",
				"RB=\"",
				"Ordinal=1",
				SEARCH_FILTERS,
				LAST);
		
				web_reg_save_param_ex(
				"ParamName=OutBoundFlight2",
				"LB=\"outboundFlight\" value=\"",
				"RB=\"",
				"Ordinal=2",
				SEARCH_FILTERS,
				LAST);
		
				web_reg_save_param_ex(
				"ParamName=OutBoundFlight3",
				"LB=\"outboundFlight\" value=\"",
				"RB=\"",
				"Ordinal=3",
				SEARCH_FILTERS,
				LAST);
		
				web_reg_save_param_ex(
				"ParamName=OutBoundFlight4",
				"LB=\"outboundFlight\" value=\"",
				"RB=\"",
				"Ordinal=4",
				SEARCH_FILTERS,
				LAST);
			
				typeseat = lr_eval_string("{TypeofSeat}");
				lr_save_string(typeseat, "TypeSeat");
		
				web_submit_data("reservations.pl_2", 
				"Action=http://localhost:1080/cgi-bin/reservations.pl", 
				"Method=POST", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
				"Snapshot=t6.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=advanceDiscount", "Value=0", ENDITEM, 
				"Name=depart", "Value={HomeCity}", ENDITEM, 
				"Name=departDate", "Value={DepartDate}", ENDITEM, 
				"Name=arrive", "Value={ArriveCity1}", ENDITEM, 
				"Name=returnDate", "Value={ReturnDate}", ENDITEM, 
				"Name=numPassengers", "Value=1", ENDITEM, 
				"Name=seatPref", "Value={SeatingPref}", ENDITEM, 
				"Name=seatType", "Value={TypeSeat}", ENDITEM, 
				"Name=.cgifields", "Value=roundtrip", ENDITEM, 
				"Name=.cgifields", "Value=seatType", ENDITEM, 
				"Name=.cgifields", "Value=seatPref", ENDITEM, 
				"Name=findFlights.x", "Value=76", ENDITEM, 
				"Name=findFlights.y", "Value=5", ENDITEM, 
				LAST);
			
				lr_output_message("Cost1 of ticket is: %s",lr_eval_string("{CostticketOut1}"));
				lr_output_message("Cost2 of ticket is: %s",lr_eval_string("{CostticketOut2}"));
				lr_output_message("Cost3 of ticket is: %s",lr_eval_string("{CostticketOut3}"));
				lr_output_message("Cost4 of ticket is: %s",lr_eval_string("{CostticketOut4}"));
				lr_output_message("");
			
				z = lr_eval_string("{CostticketOut1}");
				mas[0] = atoi(z);
				z = lr_eval_string("{CostticketOut2}");
				mas[1] = atoi(z);
				z = lr_eval_string("{CostticketOut3}");
				mas[2] = atoi(z);
				z = lr_eval_string("{CostticketOut4}");
				mas[3] = atoi(z);
		
				masout[0] = lr_eval_string("{OutBoundFlight1}");
				masout[1] = lr_eval_string("{OutBoundFlight2}");
				masout[2] = lr_eval_string("{OutBoundFlight3}");
				masout[3] = lr_eval_string("{OutBoundFlight4}");
		
				for (i = 0; i < 4; i++) {
					if (mas[i] > 200 && mas[i] < 400) {
				
					requiredcost = mas[i];
					requiredindex = i;
					lr_save_int(requiredcost, "REQUIREDCOST");
					lr_save_int(requiredindex, "REQUIREDINDEX");
					lr_output_message("Required cost of ticket is: %s",lr_eval_string("{REQUIREDCOST}"));
					lr_output_message("Index of required cost of ticket is: %s",lr_eval_string("{REQUIREDINDEX}"));
					lr_save_string(masout[requiredindex], "OutBoundFlight");
					lr_output_message("Required OutBoundFlight is: %s",lr_eval_string("{OutBoundFlight}"));
					lr_output_message("Date of flight is: %s",lr_eval_string("{DepartDate}"));
					lr_output_message("Arrive city is: %s",lr_eval_string("{ArriveCity1}"));
					lr_output_message("Type of Seat is: %s",lr_eval_string("{TypeSeat}"));
					cost = FALSE;
					break;
				}
		
			}
			
				if (cost == FALSE) {
										
					break;
				
				}
				
				web_reg_save_param_ex(
				"ParamName=CostticketOut1",
				"LB=;",
				"RB=;{DepartDate}\"",
				"Ordinal=1",
				SEARCH_FILTERS,
				LAST);
	
				web_reg_save_param_ex(
				"ParamName=CostticketOut2",
				"LB=;",
				"RB=;{DepartDate}\"",
				"Ordinal=2",
				SEARCH_FILTERS,
				LAST);
		
				web_reg_save_param_ex(
				"ParamName=CostticketOut3",
				"LB=;",
				"RB=;{DepartDate}\"",
				"Ordinal=3",
				SEARCH_FILTERS,
				LAST);
	
				web_reg_save_param_ex(
				"ParamName=CostticketOut4",
				"LB=;",
				"RB=;{DepartDate}\"",
				"Ordinal=4",
				SEARCH_FILTERS,
				LAST);
		
				web_reg_save_param_ex(
				"ParamName=OutBoundFlight1",
				"LB=\"outboundFlight\" value=\"",
				"RB=\"",
				"Ordinal=1",
				SEARCH_FILTERS,
				LAST);
		
				web_reg_save_param_ex(
				"ParamName=OutBoundFlight2",
				"LB=\"outboundFlight\" value=\"",
				"RB=\"",
				"Ordinal=2",
				SEARCH_FILTERS,
				LAST);
		
				web_reg_save_param_ex(
				"ParamName=OutBoundFlight3",
				"LB=\"outboundFlight\" value=\"",
				"RB=\"",
				"Ordinal=3",
				SEARCH_FILTERS,
				LAST);
		
				web_reg_save_param_ex(
				"ParamName=OutBoundFlight4",
				"LB=\"outboundFlight\" value=\"",
				"RB=\"",
				"Ordinal=4",
				SEARCH_FILTERS,
				LAST);
				
				ArriveCity = lr_eval_string("{ArriveCity2}");
				lr_save_string(ArriveCity, "ArriveCityChanges");
		
				web_submit_data("reservations.pl_2", 
				"Action=http://localhost:1080/cgi-bin/reservations.pl", 
				"Method=POST", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
				"Snapshot=t6.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=advanceDiscount", "Value=0", ENDITEM, 
				"Name=depart", "Value={HomeCity}", ENDITEM, 
				"Name=departDate", "Value={DepartDate}", ENDITEM, 
				"Name=arrive", "Value={ArriveCityChanges}", ENDITEM, 
				"Name=returnDate", "Value={ReturnDate}", ENDITEM, 
				"Name=numPassengers", "Value=1", ENDITEM, 
				"Name=seatPref", "Value={SeatingPref}", ENDITEM, 
				"Name=seatType", "Value={TypeSeat}", ENDITEM, 
				"Name=.cgifields", "Value=roundtrip", ENDITEM, 
				"Name=.cgifields", "Value=seatType", ENDITEM, 
				"Name=.cgifields", "Value=seatPref", ENDITEM, 
				"Name=findFlights.x", "Value=76", ENDITEM, 
				"Name=findFlights.y", "Value=5", ENDITEM, 
				LAST);
				
				lr_output_message("Cost1 of ticket is: %s",lr_eval_string("{CostticketOut1}"));
				lr_output_message("Cost2 of ticket is: %s",lr_eval_string("{CostticketOut2}"));
				lr_output_message("Cost3 of ticket is: %s",lr_eval_string("{CostticketOut3}"));
				lr_output_message("Cost4 of ticket is: %s",lr_eval_string("{CostticketOut4}"));
				lr_output_message("");
			
				z = lr_eval_string("{CostticketOut1}");
				mas[0] = atoi(z);
				z = lr_eval_string("{CostticketOut2}");
				mas[1] = atoi(z);
				z = lr_eval_string("{CostticketOut3}");
				mas[2] = atoi(z);
				z = lr_eval_string("{CostticketOut4}");
				mas[3] = atoi(z);
		
				masout[0] = lr_eval_string("{OutBoundFlight1}");
				masout[1] = lr_eval_string("{OutBoundFlight2}");
				masout[2] = lr_eval_string("{OutBoundFlight3}");
				masout[3] = lr_eval_string("{OutBoundFlight4}");
		
				for (i = 0; i < 4; i++) {
					if (mas[i] > 200 && mas[i] < 400) {
				
					requiredcost = mas[i];
					requiredindex = i;
					lr_save_int(requiredcost, "REQUIREDCOST");
					lr_save_int(requiredindex, "REQUIREDINDEX");
					lr_output_message("Required cost of ticket is: %s",lr_eval_string("{REQUIREDCOST}"));
					lr_output_message("Index of required cost of ticket is: %s",lr_eval_string("{REQUIREDINDEX}"));
					lr_save_string(masout[requiredindex], "OutBoundFlight");
					lr_output_message("Required OutBoundFlight is: %s",lr_eval_string("{OutBoundFlight}"));
					lr_output_message("Date of flight is: %s",lr_eval_string("{DepartDate}"));
					lr_output_message("Arrive city is: %s",lr_eval_string("{ArriveCityChanges}"));
					lr_output_message("Type of Seat is: %s",lr_eval_string("{TypeSeat}"));
					cost = FALSE;
					break;
				}
		
			}
				
		}
		
	}
		
	web_submit_data("reservations.pl_4", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={OutBoundFlight}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={TypeSeat}", ENDITEM, 
		"Name=seatPref", "Value={SeatingPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=63", ENDITEM, 
		"Name=reserveFlights.y", "Value=10", ENDITEM, 
		LAST);
	
	web_submit_data("reservations.pl_5", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={StreetAddress}", ENDITEM, 
		"Name=address2", "Value={CityStateZip}", ENDITEM, 
		"Name=pass1", "Value={FullName}", ENDITEM, 
		"Name=creditCard", "Value={CreditCard}", ENDITEM, 
		"Name=expDate", "Value={ExpDateCard}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={TypeSeat}", ENDITEM, 
		"Name=seatPref", "Value={SeatingPref}", ENDITEM, 
		"Name=outboundFlight", "Value={OutBoundFlight}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=77", ENDITEM, 
		"Name=buyFlights.y", "Value=18", ENDITEM, 
		LAST);

	return 0;
}