
/***************************************************************************************

    CarGL (Objects.h)

    Grado en Ingenier�a Multimedia.
    Pr�ctica de Gr�ficos por Computador.
    OpenGL con Shaders.
  --------------------------------------------------------------------------------------

    Noviembre 2012 - Septiembre 2016 (C) Juan Antonio Puchol Garc�a (puchol@dccia.ua.es)

****************************************************************************************/

//---------------------------------------------------------------------------
#ifndef ObjectsH
#define ObjectsH
//---------------------------------------------------------------------------

#define GLEW_STATIC

#include "Shader.h"
#include "Program.h"

#include <GL/glui.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Identificadores internos de los objetos
#define CARRETERA_ID    10
#define ESCENARIO_ID    20
#define COCHE_ID	    100 // Un coche cada 100

// IDs para los callbacks de TGui
#define LIGHT0_ENABLED_ID    200
#define LIGHT1_ENABLED_ID    201
#define LIGHT0_POSITION_ID   210
#define LIGHT1_POSITION_ID   211
#define LIGHT0_INTENSITY_ID  220
#define LIGHT1_INTENSITY_ID  221


#define ENABLE_ID            300
#define DISABLE_ID           301

#define RESET_ID             400

#define SEL_ID               500

// Datos del formato 3DS (x, y, z, A, B, C, u, v)
#define POSITION_COMPONENT_COUNT    3
#define NORMAL_COMPONENT_COUNT      3
#define UV_COMPONENT_COUNT          2
// C�lculo del stride (3+3+2)*4 = 8*4 = 32
#define STRIDE                      32

// Nombre de los attributes
#define A_POSITION  "a_Position"
#define A_NORMAL    "a_Normal"
#define A_UV        "a_UV"

// Nombre de los uniforms
#define U_PROJECTIONMATRIX      "u_ProjectionMatrix"
#define U_MVMATRIX              "u_MVMatrix"
#define U_VMATRIX               "u_VMatrix"
#define U_COLOR                 "u_Color"
#define U_LUZ0                  "u_Luz0"
#define U_TEXTUREUNIT           "u_TextureUnit"
//************************************************************** Clase TPrimtiva

class TPrimitiva
{
public: // Atributos de la clase
		int ID;				    // DisplayLists del objeto
		int tipo;               // Tipo de Objeto
		float tx,ty,tz; 	    // Posici�n del objeto
		float sx,sy,sz; 	    // Escalado del objeto
		float rx,ry,rz;     	// Rotaci�n del objeto
		float rr;               // Rotaci�n de las ruedas
		float colores[2][4];    // Color RGB y canal Alfa

		float   *modelo0;        // modelo a representar
		int     num_vertices0;   // n�mero de v�rtices

        float   *modelo1;        // modelo a representar
		int     num_vertices1;   // n�mero de v�rtices

		float   *modelo2;        // modelo a representar
		int     num_vertices2;   // n�mero de v�rtices

        float   *modelo3;        // modelo a representar
		int     num_vertices3;   // n�mero de v�rtices

		float   *modelo4;        // modelo a representar
		int     num_vertices4;   // n�mero de v�rtices

        float   *modelo5;        // modelo a representar
		int     num_vertices5;   // n�mero de v�rtices

        float   *modelo6;        // modelo a representar
		int     num_vertices6;   // n�mero de v�rtices

        float   *modelo7;        // modelo a representar
		int     num_vertices7;   // n�mero de v�rtices

        float   *modelo8;        // modelo a representar
		int     num_vertices8;   // n�mero de v�rtices

        float   *modelo9;        // modelo a representar
		int     num_vertices9;   // n�mero de v�rtices

		float   *modelo10;        // modelo a representar
		int     num_vertices10;   // n�mero de v�rtices

		float   *modelo11;        // modelo a representar
		int     num_vertices11;   // n�mero de v�rtices

		float   *modelo12;        // modelo a representar
		int     num_vertices12;   // n�mero de v�rtices

		float   *modelo13;        // modelo a representar
		int     num_vertices13;   // n�mero de v�rtices

		float   *modelo14;        // modelo a representar
		int     num_vertices14;   // n�mero de v�rtices

		float   *modelo15;        // modelo a representar
		int     num_vertices15;   // n�mero de v�rtices

		float   *modelo16;        // modelo a representar
		int     num_vertices16;   // n�mero de v�rtices

		float   *modelo17;        // modelo a representar
		int     num_vertices17;   // n�mero de v�rtices

		float   *modelo18;        // modelo a representar
		int     num_vertices18;   // n�mero de v�rtices

        float   *modelo19;        // modelo a representar
		int     num_vertices19;   // n�mero de v�rtices

		float   *modelo20;        // modelo a representar
		int     num_vertices20;   // n�mero de v�rtices

        float   *modelo21;        // modelo a representar
		int     num_vertices21;   // n�mero de v�rtices

        float   *modelo22;        // modelo a representar
		int     num_vertices22;   // n�mero de v�rtices


        float   *modelo23;        // modelo a representar
		int     num_vertices23;   // n�mero de v�rtices


        float   *modelo24;        // modelo a representar
		int     num_vertices24;   // n�mero de v�rtices


        float   *modelo25;        // modelo a representar
		int     num_vertices25;   // n�mero de v�rtices


        float   *modelo26;        // modelo a representar
		int     num_vertices26;   // n�mero de v�rtices

		float   *modelo27;        // modelo a representar
		int     num_vertices27;   // n�mero de v�rtices

		float   *modelo28;        // modelo a representar
		int     num_vertices28;   // n�mero de v�rtices

		float   *modelo29;        // modelo a representar
		int     num_vertices29;   // n�mero de v�rtices

		float   *modelo30;        // modelo a representar
		int     num_vertices30;   // n�mero de v�rtices

		float   *modelo31;        // modelo a representar
		int     num_vertices31;   // n�mero de v�rtices

        float   *modelo32;        // modelo a representar
		int     num_vertices32;   // n�mero de v�rtices

        float   *modelo33;        // modelo a representar
		int     num_vertices33;   // n�mero de v�rtices

		 float   *modelo34;        // modelo a representar
		int     num_vertices34;   // n�mero de v�rtices

		 float   *modelo35;        // modelo a representar
		int     num_vertices35;   // n�mero de v�rtices

		 float   *modelo36;        // modelo a representar
		int     num_vertices36;   // n�mero de v�rtices

		 float   *modelo37;        // modelo a representar
		int     num_vertices37;   // n�mero de v�rtices

		 float   *modelo38;        // modelo a representar
		int     num_vertices38;   // n�mero de v�rtices

		 float   *modelo39;        // modelo a representar
		int     num_vertices39;   // n�mero de v�rtices

public: // M�todos
 		TPrimitiva(int DL, int tipo);
        void __fastcall Render(int seleccion, bool reflejo=false);
};

//************************************************************** Clase TEscena

class TEscena
{
public: // Atributos de la clase
		int   	seleccion;   	// Objeto seleccionado, 0=ninguno
        int		num_objects;    // N�mero de objetos (excepto coches)
        int     num_cars;       // N�mero de coches

        TPrimitiva  *cars[10];
        TPrimitiva  *objects[100];

        // Handles de los attributes y uniforms
        int aPositionLocation;
        int aNormalLocation;
        int uProjectionMatrixLocation;
        int uMVMatrixLocation;
		int uVMatrixLocation;
		int uColorLocation;
		int uLuz0Location;

        int aUV;

        int uTextureUnit;


		glm::mat4 projectionMatrix; // Almacena la matriz de proyecci�n
        glm::mat4 viewMatrix;       // Almacena la matriz de la vista (c�mara)

		Program  *shaderProgram;    // Almacena el programa de OpenGL (ShaderProgram)

        // Vectores de luces y materiales
        GLfloat light0_ambient[4];
        GLfloat light0_diffuse[4];
        GLfloat light0_specular[4];
        GLfloat light0_position[4];

        GLfloat light1_ambient[4];
        GLfloat light1_diffuse[4];
        GLfloat light1_specular[4];
        GLfloat light1_position[4];

        GLfloat mat_ambient[4];
        GLfloat mat_diffuse[4];
        GLfloat mat_specular[4];
        GLfloat mat_shininess[1];

        float   xy_aspect;
        int     last_x, last_y;

        // live variables usadas por GLUI en TGui
        int     wireframe;
        int     z_buffer;
        int     culling;

        int     show_car;
        int     show_wheels;
        int     show_road;

        GLfloat view_position[3];
        GLfloat view_rotate[16];
        float   scale;

public: // M�todos
		TEscena();

        void __fastcall InitGL();
		void __fastcall Render();
		void __fastcall RenderCars(bool reflejo=false);
		void __fastcall RenderObjects(bool reflejo=false);

		void __fastcall AddCar(TPrimitiva *car);
		void __fastcall AddObject(TPrimitiva *object);

		TPrimitiva __fastcall *GetCar(int id);

		void __fastcall Pick3D(int mouse_x, int mouse_y);


};

//************************************************************** Clase TGui

class TGui
{
public:
        int             window_id;

        // live variables usadas por GLUI
        int             sel;
        int             enable_panel2;
        int             light0_enabled;
        int             light1_enabled;
        float           light0_intensity;
        float           light1_intensity;
        float           light0_position[4];
        float           light1_position[4];

        GLUI            *glui, *glui2;
        GLUI_Spinner    *light0_spinner;
        GLUI_Spinner    *light1_spinner;
        GLUI_RadioGroup *radio;
        GLUI_Panel      *obj_panel;
        GLUI_Rotation   *view_rot;

public:
        TGui();
        void __fastcall Init(int main_window);
        void __fastcall ControlCallback(int control);
        void __fastcall Idle( void );
        void __fastcall Reshape( int x, int y  );
        void __fastcall Motion( int x, int y  );
        void __fastcall Mouse(int button, int button_state, int x, int y );
};

//************************************************************** Variables de clase

extern TEscena  escena;
extern TGui     gui;

#endif
