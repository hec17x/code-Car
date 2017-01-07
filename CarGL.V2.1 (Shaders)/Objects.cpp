
/****************************************************************************************

    CarGL (Objects.cpp)

    Grado en Ingeniería Multimedia.
    Práctica de Gráficos por Computador.
    OpenGL con Shaders.
  ---------------------------------------------------------------------------------------

    Noviembre 2012 - Septiembre 2016 (C) Juan Antonio Puchol García (puchol@dccia.ua.es)


*****************************************************************************************/

#include "Objects.h"
#include <GL/glui.h>
#include "loadjpeg.c"
#include "load3ds.c"

unsigned char* textura ;
GLuint idTextura[55];

// Variable para inicializar los vectores correpondientes con los valores iniciales
GLfloat light0_ambient_c[4]  = {   0.2f,   0.2f,  0.2f, 1.0f };
GLfloat light0_diffuse_c[4]  = {   0.8f,   0.8f,  0.8f, 1.0f };
GLfloat light0_specular_c[4] = {   1.0f,   1.0f,  1.0f, 1.0f };
GLfloat light0_position_c[4] = {-100.0f, 100.0f, 50.0f, 1.0f };

GLfloat light1_ambient_c[4]  = {   0.2f,   0.2f,  0.2f, 1.0f };
GLfloat light1_diffuse_c[4]  = {   0.8f,   0.8f,  0.8f, 1.0f };
GLfloat light1_specular_c[4] = {   1.0f,   1.0f,  1.0f, 1.0f };
GLfloat light1_position_c[4] = {   0.0f, 100.0f,  0.0f, 1.0f };

GLfloat mat_ambient_c[4]    = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_diffuse_c[4]    = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat mat_specular_c[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat mat_shininess_c[1] = { 100.0f };

// Matriz de 4x4 = (I)
float view_rotate_c[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
float view_position_c[3] = { 0.0, -2.0, -9.0 };

float coloresc_c[2][4] = { {0.8, 0.5, 0.0, 1.0}, {0.5, 0.5, 0.5, 1.0}}; // Color del coche
float coloresr_c[2][4] = { {0.3, 0.3, 0.3, 1.0}, {1.0, 1.0, 1.0, 1.0}}; // Color de la carretera

//************************************************************** Variables de clase

TEscena escena;
TGui    gui;

//************************************************************** Clase TPrimitiva

TPrimitiva::TPrimitiva(int DL, int t)
{

    ID   = DL;
    tipo = t;

    sx = sy = sz = 1;
    rx = ry = rz = 0;
	switch (tipo) {
		case CARRETERA_ID: {  // Creación de la carretera
		    tx = ty = tz = 0;

            memcpy(colores, coloresr_c, 8*sizeof(float));

            //************************ Cargar modelos 3ds ***********************************
            // formato 8 floats por vértice (x, y, z, A, B, C, u, v)
            modelo0 = Load3DS("../../Modelos/Road.3ds", &num_vertices0);
            modelo1 = Load3DS("../../Modelos/Lines.3ds", &num_vertices1);

            break;
		}
		case COCHE_ID: { // Creación del coche

		    tx = -2.0;
		    ty =  0.0;
		    tz =  0.0;
		    rr =  0.0;

		    memcpy(colores, coloresc_c, 8*sizeof(float));

            //************************ Cargar modelos 3ds ***********************************
            // formato 8 floats por vértice (x, y, z, A, B, C, u, v)
            modelo0 = Load3DS("../../Modelos/FordF250.3ds", &num_vertices0);
            modelo1 = Load3DS("../../Modelos/RuedaFord.3ds", &num_vertices1);
            break;
		}
		case ESCENARIO_ID:{
            tx = ty = tz = 0;

            memcpy(colores, coloresr_c, 8*sizeof(float));

            //************************ Cargar modelos 3ds ***********************************
            // formato 8 floats por vértice (x, y, z, A, B, C, u, v)
            modelo0 = Load3DS("../../Modelos/Farolas.3ds", &num_vertices0);
            modelo1 = Load3DS("../../Modelos/Suelo.3ds", &num_vertices1);
            modelo2 = Load3DS("../../Modelos/semaforo.3ds", &num_vertices2);
            modelo3 = Load3DS("../../Modelos/bancos.3ds", &num_vertices3);
            modelo4 = Load3DS("../../Modelos/stop.3ds", &num_vertices4);
            modelo5 = Load3DS("../../Modelos/Ed1.3ds", &num_vertices5);
            modelo6 = Load3DS("../../Modelos/Suelo_Ed2.3ds", &num_vertices6);
            modelo7 = Load3DS("../../Modelos/Ed2.3ds", &num_vertices7);
            modelo8 = Load3DS("../../Modelos/Suelo_Ed3.3ds", &num_vertices8);
            modelo9 = Load3DS("../../Modelos/Ed3.3ds", &num_vertices9);
            modelo10 = Load3DS("../../Modelos/Suelo_Ed4.3ds", &num_vertices10);
            modelo11 = Load3DS("../../Modelos/Ed4.3ds", &num_vertices11);
            modelo12 = Load3DS("../../Modelos/Suelo_Ed5.3ds", &num_vertices12);
            modelo13 = Load3DS("../../Modelos/Ed5.3ds", &num_vertices13);
            modelo14 = Load3DS("../../Modelos/Suelo_Ed6.3ds", &num_vertices14);
            modelo15 = Load3DS("../../Modelos/Ed6.3ds", &num_vertices15);
            modelo16 = Load3DS("../../Modelos/Suelo_Ed7.3ds", &num_vertices16);
            modelo17 = Load3DS("../../Modelos/Ed7.3ds", &num_vertices17);
            modelo18 = Load3DS("../../Modelos/Suelo_Ed8.3ds", &num_vertices18);
            modelo19 = Load3DS("../../Modelos/Ed8.3ds", &num_vertices19);
            modelo20 = Load3DS("../../Modelos/Suelo_Ed9.3ds", &num_vertices20);
            modelo21 = Load3DS("../../Modelos/Ed9.3ds", &num_vertices21);
            modelo22 = Load3DS("../../Modelos/Suelo_Ed10.3ds", &num_vertices22);
            modelo23 = Load3DS("../../Modelos/Ed10.3ds", &num_vertices23);
            modelo24 = Load3DS("../../Modelos/Ed11.3ds", &num_vertices24);
            modelo25 = Load3DS("../../Modelos/Ed12.3ds", &num_vertices25);
            modelo26 = Load3DS("../../Modelos/Ed13.3ds", &num_vertices26);
            modelo27 = Load3DS("../../Modelos/Suelo_Ed14.3ds", &num_vertices27);
            modelo28 = Load3DS("../../Modelos/Ed14.3ds", &num_vertices28);
            modelo29 = Load3DS("../../Modelos/Suelo_Ed15.3ds", &num_vertices29);
            modelo30 = Load3DS("../../Modelos/Ed15.3ds", &num_vertices30);
            modelo31 = Load3DS("../../Modelos/Suelo_solo.3ds", &num_vertices31);
            modelo32 = Load3DS("../../Modelos/Suelo_Ed16.3ds", &num_vertices32);
            modelo33 = Load3DS("../../Modelos/Ed16.3ds", &num_vertices33);
            modelo34 = Load3DS("../../Modelos/Suelo_Ed17.3ds", &num_vertices34);
            modelo35 = Load3DS("../../Modelos/Ed17.3ds", &num_vertices35);
            modelo36 = Load3DS("../../Modelos/Suelo_solo1.3ds", &num_vertices36);
            modelo37 = Load3DS("../../Modelos/Suelo_solo2.3ds", &num_vertices37);
            modelo38 = Load3DS("../../Modelos/Suelo_solo3.3ds", &num_vertices38);
            modelo39 = Load3DS("../../Modelos/acera.3ds", &num_vertices39);
            break;
		}

	} // switch
}

void __fastcall TPrimitiva::Render(int seleccion, bool reflejo)
{
    glm::mat4   modelMatrix;
    glm::mat4   modelViewMatrix;
    switch (tipo) {

        case CARRETERA_ID: {
            if (escena.show_road) {
                // Cálculo de la ModelView
                modelMatrix     = glm::mat4(1.0f); // matriz identidad
                modelViewMatrix = escena.viewMatrix * modelMatrix;
                // Envía nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                // Pintar la carretera
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices0);

                // Pintar las líneas
                glUniform4fv(escena.uColorLocation, 1, colores[1]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices1);


            }
            break;
        }
        case COCHE_ID: {
            if (escena.show_car) {
                glUniform4fv(escena.uColorLocation, 1, (const GLfloat *) colores[0]);
                // Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

                // Cálculo de la matriz modelo
                modelMatrix     = glm::mat4(1.0f); // matriz identidad
                modelMatrix     = glm::translate(modelMatrix,glm::vec3(tx, ty, tz));

                modelViewMatrix = escena.viewMatrix * modelMatrix;

                // Envía nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
            }


            if (escena.show_wheels)
            {
                glUniform4fv(escena.uColorLocation, 1, (const GLfloat *) colores[1]);
                // Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1+3);

                // RUEDA Delantera Izquierda : Cálculo de la matriz modelo
                modelMatrix     = glm::mat4(1.0f); // matriz identidad

                modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx+0.95, ty+0.45, tz));
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(rr), glm::vec3(1,0,0));      // en radianes
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(180.0), glm::vec3(0,0,1));   // en radianes

                modelViewMatrix = escena.viewMatrix * modelMatrix;

                // Envia nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices1);

                // RUEDA Trasera Derecha : Cálculo de la matriz modelo
                modelMatrix     = glm::mat4(1.0f); // matriz identidad
                modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx-0.95, ty+0.45, tz));
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(rr), glm::vec3(1,0,0));

                modelViewMatrix = escena.viewMatrix * modelMatrix;

                // Envia nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices1);

                // RUEDA Delantera Izquierda : Cálculo de la matriz modelo
                modelMatrix     = glm::mat4(1.0f); // matriz identidad

                modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx+0.95, ty+0.45, tz-4.24));
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(rr), glm::vec3(1,0,0));      // en radianes
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(180.0), glm::vec3(0,0,1));   // en radianes

                modelViewMatrix = escena.viewMatrix * modelMatrix;

                // Envia nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices1);

                // RUEDA Trasera Derecha : Cálculo de la matriz modelo
                modelMatrix     = glm::mat4(1.0f); // matriz identidad
                modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx-0.95, ty+0.45, tz-4.24));
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(rr), glm::vec3(1,0,0));

                modelViewMatrix = escena.viewMatrix * modelMatrix;

                // Envia nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices1);
                break;
            }

        }
        case ESCENARIO_ID: {

                 if (escena.show_road) {
               // Cálculo de la ModelView
                modelMatrix     = glm::mat4(1.0f); // matriz identidad
                modelMatrix     = glm::translate(modelMatrix,glm::vec3(tx, ty, tz));
                modelMatrix     = glm::scale(modelMatrix,glm::vec3(2, 2, 2));
                modelViewMatrix = escena.viewMatrix * modelMatrix;
                // Envía nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                // Pintar Farolas
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);
                glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[2]);
                glUniform1i(escena.uTextureUnit, 0);


                glDrawArrays(GL_TRIANGLES, 0, num_vertices0);

                     // Pintar la carretera


                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1+3);
                glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[0]);
                glUniform1i(escena.uTextureUnit, 0);

                glDisable(GL_TEXTURE_2D);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices1);


                      // Pintar la acera
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo39);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo39+3);
                glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo39+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[1]);
                glUniform1i(escena.uTextureUnit, 0);

                glDisable(GL_TEXTURE_2D);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices39);
/*

/*
                     // Pintar los semaforos
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo2);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo2+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices2);

*/
                // Pintar los bancos
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo3);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo3+3);
                  glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo3+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[3]);
                glUniform1i(escena.uTextureUnit, 0);

                glDisable(GL_TEXTURE_2D);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices3);
/*
                  // Pintar los stop
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo4);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo4+3);
                 glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo4+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[4]);
                glUniform1i(escena.uTextureUnit, 0);

                glDisable(GL_TEXTURE_2D);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices4);*/

                   // Pintar los edificio1
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo5);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo5+3);
                 glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo5+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[5]);
                glUniform1i(escena.uTextureUnit, 0);

                glDisable(GL_TEXTURE_2D);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices5);

                    // Pintar los suelo edificio2
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo6);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo6+3);
                      glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo6+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[22]);
                glUniform1i(escena.uTextureUnit, 0);

                glDisable(GL_TEXTURE_2D);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices6);

                    // Pintar los edificio2
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo7);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo7+3);
                    glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo7+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[6]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices7);

               // Pintar los suelo edificio3
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo8);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo8+3);
                glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo8+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[23]);
                glUniform1i(escena.uTextureUnit, 0);

                glDisable(GL_TEXTURE_2D);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices8);

                // Pintar los edificio3
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo9);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo9+3);
                  glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo9+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[7]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices9);


                // Pintar los suelo edificio4
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo10);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo10+3);
                glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo10+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[24]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices10);

                 // Pintar los edificio4
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo11);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo11+3);
                glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo11+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[8]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices11);

                // Pintar los suelo edificio5
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo12);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo12+3);
                            glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo12+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[25]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices12);

                // Pintar los edificio5
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo13);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo13+3);
                glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo13+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[9]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices13);

/*
                // Pintar los suelo edificio6
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo14);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo14+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices14);
*/
                // Pintar los edificio6
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo15);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo15+3);
                glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo15+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[10]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices15);
/*
                 // Pintar los suelo edificio7
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo16);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo16+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices16);
*/
                // Pintar los edificio7
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo17);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo17+3);
                 glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo17+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[11]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices17);
/*
                  // Pintar los suelo edificio8
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo18);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo18+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices18);
*/
                // Pintar los edificio8
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo19);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo19+3);
                 glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo19+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[12]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices19);
/*
                  // Pintar los suelo edificio9
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo20);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo20+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices20);
*/
                // Pintar los edificio9
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo21);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo21+3);
                 glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo21+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[13]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices21);
/*
                // Pintar los suelo edificio10
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo22);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo22+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices22);
*/

                // Pintar los edificio10
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo23);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo23+3);
                   glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo23+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[14]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices23);

                 // Pintar los edificio11
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo24);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo24+3);
                 glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo24+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[15]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices24);

                 // Pintar los edificio12
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo25);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo25+3);
                 glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo25+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[16]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices25);

               // Pintar los edificio13
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo26);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo26+3);
                               glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo26+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[17]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices26);
 /*
                // Pintar los suelo edificio14
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo27);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo27+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices27);
*/

                 // Pintar los edificio14
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo28);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo28+3);
                             glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo28+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[18]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices28);
/*
                 // Pintar los suelo edificio15
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo29);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo29+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices29);

*/
                 // Pintar los edificio15
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo30);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo30+3);
                    glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo30+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[19]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices30);

/*
                 // Pintar los suelo solo
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo31);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo31+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices31);


                  // Pintar los suelo edificio16
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo32);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo32+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices32);
*/

                 // Pintar los edificio16
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo33);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo33+3);
                 glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo33+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[20]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices33);

   /*                     // Pintar los suelo edificio17
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo34);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo34+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices34);

*/
                 // Pintar los edificio17
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo35);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo35+3);
                glVertexAttribPointer(escena.aUV, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo35+6);

                glActiveTexture(GL_TEXTURE0);
                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, idTextura[21]);
                glUniform1i(escena.uTextureUnit, 0);
                glDrawArrays(GL_TRIANGLES, 0, num_vertices35);
/*
                  // Pintar los suelo solo1
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo36);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo36+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices36);


                   // Pintar los suelo solo2
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo37);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo37+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices37);

                   // Pintar los suelo solo3
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo38);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo38+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices38);
*/
                }
                break;
        }
    } // switch

}

//************************************************************** Clase TEscena

TEscena::TEscena() {

    seleccion = 1;
    num_objects = 0;
    num_cars = 0;

    show_car = 1;
    show_wheels = 1;
    show_road = 1;

    // live variables usadas por GLUI en TGui
    wireframe = 0;
    z_buffer = 1;
    culling = 0;

    scale = 1.0;
    xy_aspect = 1;
    last_x = 0;
    last_y = 0;

    memcpy(view_position, view_position_c, 3*sizeof(float));
    memcpy(view_rotate, view_rotate_c, 16*sizeof(float));

    memcpy(light0_ambient, light0_ambient_c, 4*sizeof(float));

    memcpy(light0_ambient, light0_ambient_c, 4*sizeof(float));
    memcpy(light0_diffuse, light0_diffuse_c, 4*sizeof(float));
    memcpy(light0_specular, light0_specular_c, 4*sizeof(float));
    memcpy(light0_position, light0_position_c, 4*sizeof(float));

    memcpy(light1_ambient, light1_ambient_c, 4*sizeof(float));
    memcpy(light1_diffuse, light1_diffuse_c, 4*sizeof(float));
    memcpy(light1_specular, light1_specular_c, 4*sizeof(float));
    memcpy(light1_position, light1_position_c, 4*sizeof(float));

    memcpy(mat_ambient, mat_ambient_c, 4*sizeof(float));
    memcpy(mat_diffuse, mat_diffuse_c, 4*sizeof(float));
    memcpy(mat_specular, mat_specular_c, 4*sizeof(float));
    memcpy(mat_shininess, mat_shininess_c, 1*sizeof(float));
}

void __fastcall TEscena::InitGL()
{
    int tx, ty, tw, th;

    // Habilita el z_buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // Inicialización de GLEW
    std::cout << "Inicializando GLEW" << std::endl << std::endl;
    if(glewInit() != GLEW_OK)
        throw std::runtime_error("glewInit failed");

    // print out some info about the graphics drivers
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendedor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    // Carga de los Shaders
    std::cout << std::endl << "Cargando Shaders" << std::endl;

    Shader shader;

    std::vector<GLuint> shaders;
    shaders.push_back(shader.LoadShader("../../Shaders/VertexShader.glsl", GL_VERTEX_SHADER));
    //std::cout << "Vertex Shader: " << shader.ReturnShaderID() << std::endl;
    shaders.push_back(shader.LoadShader("../../Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER));
    //std::cout << "Fragment Shader: " << shader.ReturnShaderID() << std::endl;
    shaderProgram = new Program(shaders);

    //std::cout << "Shader Program: " << shaderProgram->ReturnProgramID() << std::endl;

    glUseProgram(shaderProgram->ReturnProgramID());
    //glValidateProgram(shaderProgram->ReturnProgramID());

    aPositionLocation=shaderProgram->attrib(A_POSITION);
    aNormalLocation=shaderProgram->attrib(A_NORMAL);
    aUV=shaderProgram->attrib(A_UV);
    uTextureUnit=shaderProgram->uniform(U_TEXTUREUNIT);

    uProjectionMatrixLocation=shaderProgram->uniform(U_PROJECTIONMATRIX);
    uMVMatrixLocation=shaderProgram->uniform(U_MVMATRIX);
    uVMatrixLocation=shaderProgram->uniform(U_VMATRIX);
    uColorLocation=shaderProgram->uniform(U_COLOR);
    uLuz0Location=shaderProgram->uniform(U_LUZ0);

    /*
    std::cout << "a_Position Location: " << aPositionLocation << std::endl;
    std::cout << "a_Normal Location: " << aNormalLocation << std::endl;

    std::cout << "u_ProjectionMatrix Location: " << uProjectionMatrixLocation << std::endl;
    std::cout << "u_MVMatrix Location: " << uMVMatrixLocation << std::endl;
    std::cout << "u_VMatrix Location: " << uVMatrixLocation << std::endl;
    std::cout << "u_Color Location: " << uColorLocation << std::endl;
    std::cout << "u_Luz0 Location: " << uLuz0Location << std::endl;
    */

    // Habilitamos el paso de attributes
    glEnableVertexAttribArray(aPositionLocation);
    glEnableVertexAttribArray(aNormalLocation);
    if(aUV!=NULL)
    {
            glEnableVertexAttribArray(aUV);
    }


    glGenTextures(55, idTextura);

    int width;
    int height;

    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/road.jpg", &width, &height);
    glGenTextures(1, &idTextura[0]);
    glBindTexture(GL_TEXTURE_2D, idTextura[0]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);;


    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/acera.jpg", &width, &height);
    glGenTextures(1, &idTextura[1]);
    glBindTexture(GL_TEXTURE_2D, idTextura[1]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

      width = 300;
    height = 300;
    textura = LoadJPEG("../../res/tex3_farola.jpg", &width, &height);
    glGenTextures(1, &idTextura[2]);
    glBindTexture(GL_TEXTURE_2D, idTextura[2]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/text3_banco.jpg", &width, &height);
    glGenTextures(1, &idTextura[3]);
    glBindTexture(GL_TEXTURE_2D, idTextura[3]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        width = 620;
    height = 620;
    textura = LoadJPEG("../../res/test.jpg", &width, &height);
    glGenTextures(1, &idTextura[4]);
    glBindTexture(GL_TEXTURE_2D, idTextura[4]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(0);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex_ed1.jpg", &width, &height);
    glGenTextures(1, &idTextura[5]);
    glBindTexture(GL_TEXTURE_2D, idTextura[5]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_ed2.jpg", &width, &height);
    glGenTextures(1, &idTextura[6]);
    glBindTexture(GL_TEXTURE_2D, idTextura[6]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


     width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_ed3.jpg", &width, &height);
    glGenTextures(1, &idTextura[7]);
    glBindTexture(GL_TEXTURE_2D, idTextura[7]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

     width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_ed4.jpg", &width, &height);
    glGenTextures(1, &idTextura[8]);
    glBindTexture(GL_TEXTURE_2D, idTextura[8]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

         width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_ed5.jpg", &width, &height);
    glGenTextures(1, &idTextura[9]);
    glBindTexture(GL_TEXTURE_2D, idTextura[9]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


         width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_ed6.jpg", &width, &height);
    glGenTextures(1, &idTextura[10]);
    glBindTexture(GL_TEXTURE_2D, idTextura[10]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_ed7.jpg", &width, &height);
    glGenTextures(1, &idTextura[11]);
    glBindTexture(GL_TEXTURE_2D, idTextura[11]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_ed8.jpg", &width, &height);
    glGenTextures(1, &idTextura[12]);
    glBindTexture(GL_TEXTURE_2D, idTextura[12]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

      width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_ed9.jpg", &width, &height);
    glGenTextures(1, &idTextura[13]);
    glBindTexture(GL_TEXTURE_2D, idTextura[13]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


          width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex2_ed10.jpg", &width, &height);
    glGenTextures(1, &idTextura[14]);
    glBindTexture(GL_TEXTURE_2D, idTextura[14]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



          width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex4_ed11.jpg", &width, &height);
    glGenTextures(1, &idTextura[15]);
    glBindTexture(GL_TEXTURE_2D, idTextura[15]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

              width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex3_ed12.jpg", &width, &height);
    glGenTextures(1, &idTextura[16]);
    glBindTexture(GL_TEXTURE_2D, idTextura[16]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex2_ed13.jpg", &width, &height);
    glGenTextures(1, &idTextura[17]);
    glBindTexture(GL_TEXTURE_2D, idTextura[17]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex3_ed14.jpg", &width, &height);
    glGenTextures(1, &idTextura[18]);
    glBindTexture(GL_TEXTURE_2D, idTextura[18]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_ed15.jpg", &width, &height);
    glGenTextures(1, &idTextura[19]);
    glBindTexture(GL_TEXTURE_2D, idTextura[19]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

     width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_ed16.jpg", &width, &height);
    glGenTextures(1, &idTextura[20]);
    glBindTexture(GL_TEXTURE_2D, idTextura[20]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_ed17.jpg", &width, &height);
    glGenTextures(1, &idTextura[21]);
    glBindTexture(GL_TEXTURE_2D, idTextura[21]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


     width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_sed2.jpg", &width, &height);
    glGenTextures(1, &idTextura[22]);
    glBindTexture(GL_TEXTURE_2D, idTextura[22]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_sed3.jpg", &width, &height);
    glGenTextures(1, &idTextura[23]);
    glBindTexture(GL_TEXTURE_2D, idTextura[23]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

     width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_sed4.jpg", &width, &height);
    glGenTextures(1, &idTextura[24]);
    glBindTexture(GL_TEXTURE_2D, idTextura[24]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    width = 512;
    height = 512;
    textura = LoadJPEG("../../res/tex1_sed5.jpg", &width, &height);
    glGenTextures(1, &idTextura[25]);
    glBindTexture(GL_TEXTURE_2D, idTextura[25]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);
    glGenerateMipmap(GL_TEXTURE_2D);
    free(textura);
    glBindTexture(GL_TEXTURE_2D, 0);
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);




    // Estableciendo la matriz de proyección perspectiva
    GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
    xy_aspect = (float)tw / (float)th;
    projectionMatrix = glm::perspective(45.0f, xy_aspect, 0.1f, 1000.0f);
    glUniformMatrix4fv(uProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}


/************************** TEscena::AddCar(TPrimitiva *car) *****************/

void __fastcall TEscena::AddCar(TPrimitiva *car)
{
    cars[num_cars] = car;
    num_cars++;
}

/******************** TEscena::AddObject(TPrimitiva *object) *****************/

void __fastcall TEscena::AddObject(TPrimitiva *object)
{
    objects[num_objects] = object;
    num_objects++;
}

/******************** TPrimitiva *TEscena::GetCar(int id) ********************/

TPrimitiva __fastcall *TEscena::GetCar(int id)
{
    TPrimitiva *p=NULL;

    for (int i=0; i<num_cars; i++)
    {
        if (cars[i]->ID==id)
        {
            p = cars[i];
        }

    }
    return(p);
}

/******************** TEscena::RenderCars() **********************************/

void __fastcall TEscena::RenderCars(bool reflejo) {

    for (int i=0; i<num_cars; i++)
    {
        cars[i]->Render(seleccion, reflejo);
    }
}

/******************** TEscena::RenderCars() **********************************/

void __fastcall TEscena::RenderObjects(bool reflejo) {

    for (int i=0; i<num_objects; i++)
    {
        objects[i]->Render(seleccion, reflejo);
    }
}

/***************************************** TEscena::Render() *****************/

void __fastcall TEscena::Render()
{
    glm::mat4 rotateMatrix;

    glClearColor(0.0, 0.7, 0.9, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Cálculo de la vista (cámara)
    viewMatrix      = glm::mat4(1.0f);
    rotateMatrix    = glm::make_mat4(view_rotate);
    viewMatrix      = glm::translate(viewMatrix,glm::vec3(view_position[0], view_position[1], view_position[2]));
    viewMatrix      = viewMatrix*rotateMatrix;
    viewMatrix      = glm::scale(viewMatrix,glm::vec3(scale, scale, scale));

    glUniform1i(uLuz0Location, gui.light0_enabled);
    glUniformMatrix4fv(uVMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix)); // Para la luz matrix view pero sin escalado!

    // Dibujar carretera y objetos
    RenderObjects(seleccion);

    // Dibujar coches
    RenderCars(seleccion);

    glutSwapBuffers();
}

// Selecciona un objeto a través del ratón
void __fastcall TEscena::Pick3D(int mouse_x, int mouse_y)
{
}

//************************************************************** Clase TGui

TGui::TGui()
{
    sel = 1;
    enable_panel2 = 1;
    light0_enabled = 1;
    light1_enabled = 1;
    light0_intensity = 0.8;
    light1_intensity = 0.8;
    memcpy(light0_position, light0_position_c, 4*sizeof(float));
    memcpy(light1_position, light1_position_c, 4*sizeof(float));
}

void controlCallback(int control)
{
    gui.ControlCallback(control);
}

void __fastcall TGui::Init(int main_window) {

    /****************************************************/
    /*        Código con el interfaz Gráfico GLUI       */
    /****************************************************/
    printf( "GLUI version: %3.2f\n", GLUI_Master.get_version() );

    window_id = main_window;

    /*** Crea a ventana lateral ***/
    glui = GLUI_Master.create_glui_subwindow( window_id, GLUI_SUBWINDOW_RIGHT );

    // Añade una separación
    new GLUI_StaticText( glui, "" );

    // Añade un panel con texto con el valor de la selección
    GLUI_Panel *panel0 = new GLUI_Panel(glui, "Seleccion");
    GLUI_RadioGroup *radioGroup = new GLUI_RadioGroup(panel0, &sel, SEL_ID, controlCallback);
    glui->add_radiobutton_to_group(radioGroup, "NINGUNO");


    glui->add_radiobutton_to_group(radioGroup, "COCHE 1");
    glui->add_radiobutton_to_group(radioGroup, "COCHE 2");


    // Añade una separación
    new GLUI_StaticText( glui, "" );

    obj_panel = new GLUI_Rollout(glui, "Propiedades", true );

    /***** Control para las propiedades de escena *****/

    new GLUI_Checkbox( obj_panel, "Modo Alambrico", &escena.wireframe, 1, controlCallback );
    glui->add_column_to_panel(obj_panel, true);
    new GLUI_Checkbox( obj_panel, "Culling", &escena.culling, 1, controlCallback );
    new GLUI_Checkbox( obj_panel, "Z Buffer", &escena.z_buffer, 1, controlCallback );

    /******** Añade controles para las luces ********/

    // Añade una separación
    new GLUI_StaticText( glui, "" );

    GLUI_Rollout *roll_lights = new GLUI_Rollout(glui, "Luces", false );

    GLUI_Panel *light0 = new GLUI_Panel( roll_lights, "Luz 1" );
    GLUI_Panel *light1 = new GLUI_Panel( roll_lights, "Luz 2" );

    new GLUI_Checkbox( light0, "Encendida", &light0_enabled, LIGHT0_ENABLED_ID, controlCallback );
    light0_spinner = new GLUI_Spinner( light0, "Intensidad:", &light0_intensity,
                            LIGHT0_INTENSITY_ID, controlCallback );
    light0_spinner->set_float_limits( 0.0, 1.0 );
    GLUI_Scrollbar *sb;
    sb = new GLUI_Scrollbar( light0, "X",GLUI_SCROLL_HORIZONTAL,
                            &escena.light0_position[0],LIGHT0_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);
    sb = new GLUI_Scrollbar( light0, "Y",GLUI_SCROLL_HORIZONTAL,
                            &escena.light0_position[1],LIGHT0_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);
    sb = new GLUI_Scrollbar( light0, "Z",GLUI_SCROLL_HORIZONTAL,
                            &escena.light0_position[2],LIGHT0_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);

    new GLUI_Checkbox( light1, "Encendida", &light1_enabled, LIGHT1_ENABLED_ID, controlCallback );
    light1_spinner = new GLUI_Spinner( light1, "Intensidad:", &light1_intensity,
                            LIGHT1_INTENSITY_ID, controlCallback );
    light1_spinner->set_float_limits( 0.0, 1.0 );
    sb = new GLUI_Scrollbar( light1, "X",GLUI_SCROLL_HORIZONTAL,
                            &escena.light1_position[0],LIGHT1_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);
    sb = new GLUI_Scrollbar( light1, "Y",GLUI_SCROLL_HORIZONTAL,
                            &escena.light1_position[1],LIGHT1_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);
    sb = new GLUI_Scrollbar( light1, "Z",GLUI_SCROLL_HORIZONTAL,
                            &escena.light1_position[2],LIGHT1_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);


    // Añade una separación
    new GLUI_StaticText( glui, "" );

    /***  Rollout de Opciones ***/
    GLUI_Rollout *options = new GLUI_Rollout(glui, "Opciones", true );
    new GLUI_Checkbox( options, "Dibujar Coche", &escena.show_car );
    new GLUI_Checkbox( options, "Dibujar Ruedas", &escena.show_wheels );
    new GLUI_Checkbox( options, "Dibujar Carretera", &escena.show_road );


    /*** Disable/Enable botones ***/
    // Añade una separación
    new GLUI_StaticText( glui, "" );
    new GLUI_Checkbox( glui, "Bloquear Movimiento", &enable_panel2 );
    // Añade una separación
    new GLUI_StaticText( glui, "" );
    new GLUI_Button( glui, "Resetear Posicion", RESET_ID, controlCallback );

    // Añade una separación
    new GLUI_StaticText( glui, "" );

    new GLUI_Separator( glui );

     // Añade una separación
    new GLUI_StaticText( glui, "" );

    new GLUI_StaticText( glui, "  Autor:" );
    new GLUI_StaticText( glui, "  2012-2016 (C) Juan Antonio Puchol  " );

    // Añade una separación
    new GLUI_StaticText( glui, "" );

    new GLUI_Separator( glui );

    // Añade una separación
    new GLUI_StaticText( glui, "" );

    /****** A 'quit' button *****/
    new GLUI_Button( glui, "Salir", 0,(GLUI_Update_CB)exit );

    // Crea la subventana inferior
    glui2 = GLUI_Master.create_glui_subwindow( window_id, GLUI_SUBWINDOW_BOTTOM );

    /**** Link windows to GLUI, and register idle callback ******/
    glui->set_main_gfx_window( window_id );
    glui2->set_main_gfx_window( window_id );

    view_rot = new GLUI_Rotation(glui2, "Rotacion Escena", escena.view_rotate );
    view_rot->set_spin( 1.0 );
    new GLUI_Column( glui2, false );
    GLUI_Translation *trans_xy = new GLUI_Translation(glui2, "Traslacion Escena XY", GLUI_TRANSLATION_XY, escena.view_position );
    trans_xy->set_speed( .005 );
    new GLUI_Column( glui2, false );
    GLUI_Translation *trans_x =  new GLUI_Translation(glui2, "Traslacion Escena X", GLUI_TRANSLATION_X, escena.view_position );
    trans_x->set_speed( .005 );
    new GLUI_Column( glui2, false );
    GLUI_Translation *trans_y = new GLUI_Translation( glui2, "Traslacion Escena Y", GLUI_TRANSLATION_Y, &escena.view_position[1] );
    trans_y->set_speed( .005 );
    new GLUI_Column( glui2, false );
    GLUI_Translation *trans_z = new GLUI_Translation( glui2, "Traslacion Escena Z", GLUI_TRANSLATION_Z, &escena.scale );
    trans_z->set_speed( .005 );

}

/**************************************** TGui::ControlCallback() *******************/

void __fastcall TGui::ControlCallback( int control )
{
    switch (control) {
        case LIGHT0_ENABLED_ID: {
            if ( light0_enabled )
                light0_spinner->enable();
            else
                light0_spinner->disable();
            break;
        }
        case LIGHT1_ENABLED_ID: {
            if ( light1_enabled )
                light1_spinner->enable();
            else
                light1_spinner->disable();
            break;
        }
        case LIGHT0_INTENSITY_ID: {

            float v[] = {
                escena.light0_diffuse[0],  escena.light0_diffuse[1],
                escena.light0_diffuse[2],  escena.light0_diffuse[3] };

            v[0] *= light0_intensity;
            v[1] *= light0_intensity;
            v[2] *= light0_intensity;
            break;
        }
        case LIGHT1_INTENSITY_ID: {

            float v[] = {
                escena.light1_diffuse[0],  escena.light1_diffuse[1],
                escena.light1_diffuse[2],  escena.light1_diffuse[3] };

            v[0] *= light1_intensity;
            v[1] *= light1_intensity;
            v[2] *= light1_intensity;
            break;
        }
        case ENABLE_ID: {
            glui2->enable();
            break;
        }
        case DISABLE_ID: {
            glui2->disable();
            break;
        }
        case RESET_ID: {
            memcpy(escena.view_position,view_position_c,3*sizeof(float));
            view_rot->reset();
            escena.scale = 1.0;
            break;
        }
        case SEL_ID: {
            escena.seleccion = sel;
            //GLUI_Master.SetFocus(true);
            glutSetWindow( glui->get_glut_window_id() );
            break;
        }
  } // switch
}

/***************************************** TGui::Idle() ***********/

void __fastcall TGui::Idle( void )
{
  /* According to the GLUT specification, the current window is
     undefined during an idle callback.  So we need to explicitly change
     it if necessary */
  if ( glutGetWindow() != window_id )
    glutSetWindow(window_id);

  /*  GLUI_Master.sync_live_all();  -- not needed - nothing to sync in this
                                       application  */
    if (enable_panel2)

        glui2->enable();
    else
        glui2->disable();

  glutPostRedisplay();
}

/**************************************** TGui::reshape() *************/

void __fastcall TGui::Reshape( int x, int y )
{
    int tx, ty, tw, th;
    GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
    glViewport( tx, ty, tw, th );

    escena.xy_aspect = (float)tw / (float)th;
    escena.projectionMatrix = glm::perspective(45.0f, escena.xy_aspect, 0.1f, 1000.0f);
    glUniformMatrix4fv(escena.uProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(escena.projectionMatrix));

    //std::cout << "xy aspect: " << escena.xy_aspect << std::endl;

    glutPostRedisplay();
}

/***************************************** gui::motion() **********/

void __fastcall TGui::Motion(int x, int y )
{
    glutPostRedisplay();
}

/***************************************** gui::Mouse() **********/

void __fastcall TGui::Mouse(int button, int button_state, int x, int y )
{
    escena.Pick3D(x, y);
}

