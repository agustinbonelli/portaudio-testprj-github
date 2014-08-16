/*
 * bone-main.c
 *
 *  Created on: 14 Jun 2014
 *      Author: bone
 */


#include "bone-config.h"



int main(void)
{
	PaError err;

	PaHostApiIndex api_index;
	const PaHostApiInfo* api_info;

	show_welcome_message();

	/* ----------------- Initialize de Port Audio API ---------------------- */
	err = Pa_Initialize();
	if(err)
	{
		fprintf(stderr,"---> PortAudio error in main initializing: %s \n",Pa_GetErrorText(err));
		return err;
	}
	/* --------------------------------------------------------------------- */

	fprintf(stdout,"\n--->PortAudio Arranco Sin problema (Error Code = %d)\n",err);


	fprintf(stdout,"\n Host System Default Input Device = %d \n",Pa_GetDefaultInputDevice());

	fprintf(stdout,"\n Host System Default Output Device = %d \n",Pa_GetDefaultOutputDevice());

	api_index = Pa_GetDefaultHostApi();

	api_info = Pa_GetHostApiInfo(api_index);

	fprintf(stdout,"\nInformación de Default Host Api:\n");

	fprintf(stdout,"Api Struct version: %d \n",api_info->structVersion);
	fprintf(stdout,"Api Name: %s \n",api_info->name);
	fprintf(stdout,"Api Device Count: %d \n",api_info->deviceCount);
	fprintf(stdout,"Api Default Input: %d \n",api_info->defaultInputDevice);
	fprintf(stdout,"Api Default Output: %d \n",api_info->defaultOutputDevice);



	/* ------------------ Terminate de Port Audio API ---------------------- */
	err = Pa_Terminate();
	if(err)
	{
		fprintf(stderr,"--->PortAudio error in main terminating: %s \n",Pa_GetErrorText(err));
		return err;
	}
	/* --------------------------------------------------------------------- */

	fprintf(stdout,"\n--->PortAudio Termino Sin problema (Error Code = %d)\n",err);
	fprintf(stdout,"--->Termino el Programa\n");
	return 0;
}

void show_welcome_message(void)
{
	const char* versiontext;

	versiontext = Pa_GetVersionText();

	fprintf(stdout,"\n ***** Welcome to Audio application using Port Audio ***** \n\n");

	fprintf(stdout,"The Port audio version number is: %d \n",Pa_GetVersion());

	fprintf(stdout,"Version Text: ");

	fprintf(stdout,"%s \n\n",versiontext);
}



