#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char* value;
	FILE* fp, *fptr;
	int no_of_customers,no_of_truck;
	int *demands;
	float *extern_cost,*resultant,*xaxis,*yaxis;
	int i=0,j=0,t,z=0,setpoint,x,row=0,column=0,neg,e=0,f=0,nt=-1;
	char buffer[1024];
	float p=0.00,temp,c;

	struct truck_details{
	int truck;
	int capacity;
	float fixed_cost;
	float var_cost;
	};
	struct truck_details *truck_info;

	       //	fp = fopen("input.txt", "r");
	fptr=fopen("Truck Output.txt","w");
	if(fptr == NULL)
	{
		printf("Can't oopen file\n");
		exit(1);
	}
	fp = fopen("input.txt", "r");        //small input file to check the correctness of the output.
	if (!fp)
		printf("Can't open file\n");
	else {
		while(fgets(buffer,1024, fp)){
			column = 0;
			row++;
			if (row == 3){
				x=0;
				value = strtok(buffer, ", ");
				while(value){
					if(x == 2){
						t=0;
						for(i=0;value[i]!='\0';i++){
							if((value[i]>='0') &&(value[i]<='9'))
								t=t*10+(value[i]-'0');
						}
						no_of_customers=t;
					}
					value = strtok(NULL, ", ");
					x++;
			       }
			       fprintf(fptr,"\nNumber of Customers are:= %d\n",no_of_customers);
			       demands=(int*)malloc(no_of_customers*sizeof(int));
			       extern_cost=(float*)malloc(no_of_customers*sizeof(float));
			       xaxis=(float*)malloc(no_of_customers*sizeof(float));
			       yaxis=(float*)malloc(no_of_customers*sizeof(float));
			       resultant=(float*)malloc((no_of_customers)*(no_of_customers)*sizeof(float));
			}
			if (row == 4){
				x=0;
				value = strtok(buffer, ", ");
				while(value){
					if(x == 2){
						t=0;
						for(i=0;value[i]!='\0';i++){
							if((value[i]>='0') &&(value[i]<='9'))
								t=t*10+(value[i]-'0');
						}
						no_of_truck=t;
					}
					value = strtok(NULL, ", ");
					x++;
			       }
			       fprintf(fptr,"\nNumber of Truck are:= %d\n",no_of_truck);
				   truck_info=(struct truck_details*) malloc((no_of_truck)*sizeof(struct truck_details));
			}
			if(row>=6 && row <no_of_customers+7){
				value = strtok(buffer, ", ");
				while (value){
					neg=0;
					if(column == 1){
					c=0.00,p=0.00,temp=0.00;
					t=0,setpoint = 0;
					for(i=0;value[i]!='\0';i++){
						if(value[i] == '-'){
							neg=1;
						}
						else{
						if(value[i] == '.'){
							setpoint=1;
							p=1.00;
						}
						else if(setpoint==1){
							temp=temp+pow(10,-p)*(value[i]-'0');
							p=p+1;
						}
						else{
								t=t*10+(value[i]-'0');
						}
						}
					}
					c=temp+t;
					if(neg==1)
						xaxis[e]=-c;
					else
						xaxis[e]=c;
					e++;
				}
				if(column == 2){
					c=0.00,p=0.00,temp=0.00;
					t=0,setpoint = 0;
					for(i=0;value[i]!='\0';i++){
						if(value[i] == '-'){
							neg=1;
						}
						else{
						if(value[i] == '.'){
							setpoint=1;
							p=1.00;
						}
						else if(setpoint==1){
							temp=temp+pow(10,-p)*(value[i]-'0');
							p=p+1;
						}
						else{
								t=t*10+(value[i]-'0');
						}
						}
					}
					c=temp+t;
					if(neg==1)
						yaxis[f]=-c;
					else
						yaxis[f]=c;
					f++;
				}
				if(column == 3){
					t=0;
					for(i=0;value[i]!='\0';i++){
					if((value[i]>='0') &&(value[i]<='9'))
						t=t*10+(value[i]-'0');
					}
					demands[z]=t;
					z++;
			       }
			       if(column == 4){
					c=0.00,p=0.00,temp=0.00;
					t=0,setpoint = 0;
					for(i=0;value[i]!='\0';i++){
						if(value[i] == '.'){
							setpoint=1;
							p=1.00;
						}
						else if(setpoint==1){
							temp=temp+pow(10,-p)*(value[i]-'0');
							p=p+1;
						}
						else{
								t=t*10+(value[i]-'0');
						}
					}
					c=temp+t;
					extern_cost[j]=c;
					j++;
				}
				value = strtok(NULL, ", ");
				column++;
				}
			}
			if(row>=8+no_of_customers && row <8+no_of_customers+no_of_truck){
				z=0;
				nt++;
				value = strtok(buffer, ", ");
				while (value){
					t=0;
					if(column == 0){
						for(i=0;value[i]!='\0';i++){
							t=t*10+(value[i]-'0');
						}
								truck_info[nt].truck=t;
					}
					if(column == 1){
						for(i=0;value[i]!='\0';i++){
							t=t*10+(value[i]-'0');
						}
						truck_info[nt].capacity=t;
					}
			       if(column == 2){
					c=0.00,p=0.00,temp=0.00;
					setpoint = 0;
					for(i=0;value[i]!='\0';i++){
						if(value[i] == '.'){
							setpoint=1;
							p=1.00;
						}
						else if(setpoint==1){
							temp=temp+pow(10,-p)*(value[i]-'0');
							p=p+1;
						}
						else{
							t=t*10+(value[i]-'0');
						}
					}
						truck_info[nt].fixed_cost=temp+t;
					}
					if(column == 3){
					c=0.00,p=0.00,temp=0.00;
					setpoint = 0;
					for(i=0;value[i]!='\0';i++)
					{
						if(value[i] == '.'){
							setpoint=1;
							p=1.00;
						}
						else if(setpoint==1){
							temp=temp+pow(10,-p)*(value[i]-'0');
							p=p+1;
						}
						else{
							t=t*10+(value[i]-'0');
						}
					}
						truck_info[nt].var_cost=temp+t;
					}
				value = strtok(NULL, ", ");
				column++;
				}
			}
		}
	}

		fclose(fp);
		fprintf(fptr,"\n\nThe Coordinates of X-axis are:\n");
		for(i=0;i<=no_of_customers;i++){
			fprintf(fptr,"%.2f\t",xaxis[i]);
		}
		fprintf(fptr,"\n\nThe Coordinates of Y-axis are:\n");
		for(i=0;i<=no_of_customers;i++){
			fprintf(fptr,"%.2f\t",yaxis[i]);
		}
		fprintf(fptr,"\n\nThe Demands are: \n");
		for(i=1;i<=no_of_customers;i++){
			fprintf(fptr,"%d\t",demands[i]);
		}
		fprintf(fptr,"\n\nThe External cost are: \n");
		for(i=1;i<=no_of_customers;i++){
			fprintf(fptr,"%.2f\t",extern_cost[i]);
		}
		fprintf(fptr,"\n\nDetails of the Truck are: \n");
		for(i=0;i<no_of_truck;i++){
			fprintf(fptr,"\nTruck Number: %d\t Truck Capacity: %d\t Truck Fixed Cost: %.2f\t Truck Var Cost: %.2f\t",truck_info[i].truck,truck_info[i].capacity,truck_info[i].fixed_cost,truck_info[i].var_cost);
			fprintf(fptr,"\n");
		}
		fprintf(fptr,"\n\nThe Distance are: \n");
		for(i=0;i<=no_of_customers;i++){
			for(j=0;j<=no_of_customers;j++){
			      *(resultant + i*no_of_customers + j)=sqrt(pow((xaxis[i]-xaxis[j]),2)+pow((yaxis[i]-yaxis[j]),2));
			      fprintf(fptr,"%.2f\t",*(resultant + i*no_of_customers+j));
			}
			fprintf(fptr,"\n");
		}
		fclose(fptr);
	 free(demands),free(extern_cost),free(resultant),free(xaxis),free(yaxis),free(truck_info);
	 printf("\n\n\n\n\n\n\t\t\t\tComplete\n");
	 return 0;
}
