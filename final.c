#include <conio.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char* value;
	FILE* fp, *fptr;
	int no_of_customers,no_of_truck,tc;
	int *demands,*input_distance,*external_node,*node_demands;
	float *extern_cost,*resultant,*xaxis,*yaxis,*truck_distance;
	int i=0,j=0,t,z=0,setpoint,x,row=0,column=0,neg,e=0,f=0,nt=-1,check;
	char buffer[1024],y;
	float p=0.00,temp,c,distance,varcost,fixcost,externalcost,objective_value;

	struct truck_details{
	int truck;
	int capacity;
	float fixed_cost;
	float var_cost;
	};
	struct truck_details *truck_info;

	clrscr();
       //	fp = fopen("input.txt", "r");
	fptr=fopen("Truck Output.txt","w");
	if(fptr == NULL)
	{
		printf("Can't oopen file\n");
		exit(1);
	}
	fp = fopen("input.txt", "r");        
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
			       check=no_of_customers+1;
			       demands=(int*)malloc(check*sizeof(int));
			       extern_cost=(float*)malloc(check*sizeof(float));
			       xaxis=(float*)malloc(check*sizeof(float));
			       yaxis=(float*)malloc(check*sizeof(float));
			       resultant=(float*)malloc((check)*(check)*sizeof(float));
			       external_node=(int*)malloc(check*sizeof(int));
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
				   truck_distance=(float*)malloc(no_of_truck*sizeof(float));
				   node_demands=(int*)malloc(no_of_truck*sizeof(int));
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
		fprintf(fptr,"\n\nThe Coordinates of the point are:\n");
		for(i=0;i<check;i++){
			fprintf(fptr,"(%.2f,%.2f)\t",xaxis[i],yaxis[i]);
		}
		fprintf(fptr,"\n\nThe Demands are: \n");
		for(i=1;i<check;i++){
			fprintf(fptr,"%d\t",demands[i]);
		}
		fprintf(fptr,"\n\nThe External cost are: \n");
		for(i=1;i<check;i++){
			fprintf(fptr,"%.2f\t",extern_cost[i]);
		}
		fprintf(fptr,"\n\nDetails of the Truck are: \n");
		for(i=0;i<no_of_truck;i++){
			fprintf(fptr,"\nTruck Number: %d\t Truck Capacity: %d\t Truck Fixed Cost: %.2f\t Truck Var Cost: %.2f\t",truck_info[i].truck,truck_info[i].capacity,truck_info[i].fixed_cost,truck_info[i].var_cost);
			fprintf(fptr,"\n");
		}
		fprintf(fptr,"\n\nThe Distance are: \n");
		for(i=0;i<check;i++){
			for(j=0;j<check;j++){
				fprintf(fptr,"%.2f\t",sqrt(pow((xaxis[i]-xaxis[j]),2)+pow((yaxis[i]-yaxis[j]),2)));
			}
			fprintf(fptr,"\n");
		}
		for(i=0;i<check;i++){
		       external_node[i]=0;
		}
		x=0,e=0,p=0,t=0;
		do{
		fprintf(fptr,"\nNumber of Route points of Truck %d: is ",x);
		printf("Enter the No of Route points\n");
		scanf("%d",&tc);
		fprintf(fptr,"%d\n",tc);
		input_distance=(int*)malloc(tc*sizeof(int));
		printf("Enter the Route Node points\n");
		for(i=0;i<tc;i++){
			scanf("%d",&input_distance[i]);
			t=t+demands[input_distance[i]];
		}
		fprintf(fptr,"Enter Route Node points are:\n");
		for(i=0;i<tc;i++){
			fprintf(fptr,"%d\t",input_distance[i]);
		}
		node_demands[p]=t;
		for(t=0;t<tc;t++){
				  external_node[input_distance[t]]=1;
				}


		for(i=0;i<=tc-2;i++){
			distance=distance+sqrt(pow((xaxis[input_distance[i]]-xaxis[input_distance[i+1]]),2)+pow((yaxis[input_distance[i]]-yaxis[input_distance[i+1]]),2));
		}
		truck_distance[e]=distance;
		x++,e++,distance=0,p++;
		printf("\nDo u have other truck Distance to Enter? Press 1 to continue");
		scanf("%d",&setpoint);
		}while(setpoint==1 && x<=no_of_truck);
		fprintf(fptr,"\nThe distance of Truck Travel are\n");
		for(i=0;i<no_of_truck;i++){
			fprintf(fptr,"Distance Travel by Truck No %d is %.2f\n",i,truck_distance[i]);
		}
		fprintf(fptr,"\nThe Truck will Fullfill demands. They are\n");
		for(i=0;i<no_of_truck;i++){
			fprintf(fptr,"Truck No = %d, Required Demands = %d\n",i,node_demands[i]);
		}
		varcost=0,fixcost=0;
		for(i=0;i<no_of_truck;i++){
			varcost=varcost+truck_distance[i]*truck_info[i].var_cost;
			fixcost=fixcost+truck_info[i].fixed_cost;
		}
		fixcost=fixcost+varcost;
		fprintf(fptr,"Variable Cost =%.2f \n",varcost);
		fprintf(fptr,"Total Cost =%.2f \n",fixcost);
		externalcost=0;
		fprintf(fptr,"\nExternal Cost is:\n");
		for(i=0;i<check;i++){
			if(external_node[i]==0){
				fprintf(fptr,"External Cost of Node %d is %.2f\n",i,extern_cost[i]);
				externalcost=externalcost+extern_cost[i];
			}
		}
		fprintf(fptr,"Total External Cost =%.2f \n",externalcost);
		objective_value=fixcost+externalcost;
		fprintf(fptr,"Objective value = %.2f\n",objective_value);
		t=0;
		for(i=0;i<no_of_truck;i++){
			if(node_demands[i]>truck_info[i].capacity){
				fprintf(fptr,"Not a Feasible System\n");
				printf("Not a Feasible System\n");
				 t=1;
				 exit(0);
			}
		}
		if(t!=1)
		fprintf(fptr,"Feasible System\n");
		fclose(fptr);
	 free(demands),free(extern_cost),free(resultant),free(xaxis),free(yaxis),free(truck_info);
	 printf("\n\n\n\n\n\n\t\t\t\tComplete\n");
	 getch();
	 return 0;
}
