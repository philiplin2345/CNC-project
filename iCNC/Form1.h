#pragma once

#include "..\CNC\INC\cnc.h"
#include <string>
#include <stdio.h>

CNC_DATA    cncData;
CNC_DATA    *cncDataPtr;
DEC_DATA	*decDataPtr; //global variable
MMI_DATA	*mmiDataPtr;
SYS_DATA	*sysDataPtr;
LINK_DATA   *linkDataPtr;
INTP_DATA   *intpDataPtr;




//**********************************************
// Real timer function
//**********************************************
#if HD_TIMER
	void _stdcall Timer_ISR_Function(LIOINT *pstINTSource)
	{
		//call real time control function
		cncRtCtl(cncDataPtr);

	}
#endif


namespace iCNC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label_feedOverride;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TrackBar^  trackBar_feedOverride;
	private: System::Windows::Forms::Label^  w_valueDisplay;
	private: System::Windows::Forms::Label^  v_valueDisplay;


	private: System::Windows::Forms::Label^  u_valueDisplay;
	private: System::Windows::Forms::Label^  w_label;
	private: System::Windows::Forms::Label^  v_label;
	private: System::Windows::Forms::Label^  u_label;
	private: System::Windows::Forms::Button^  button_m01;

	private: System::Windows::Forms::Button^  button_fh;
	private: System::Windows::Forms::Button^  button_clr;

	private: System::Windows::Forms::Button^  button_speedx100;
	private: System::Windows::Forms::Button^  button_speedx10;
	private: System::Windows::Forms::Button^  button_speedx1;
	private: System::Windows::Forms::Button^  button_zMinus;
	private: System::Windows::Forms::Button^  button_yMinus;
	private: System::Windows::Forms::Button^  button_xMinus;
	private: System::Windows::Forms::Button^  button_zPlus;
	private: System::Windows::Forms::Button^  button_xPlus;
	private: System::Windows::Forms::Timer^  NRT_Timer;
	private: System::Windows::Forms::Button^  button_yPlus;
	private: System::Windows::Forms::Button^  button_cycleStart;
	private: System::Windows::Forms::Button^  button_reset;
	private: System::Windows::Forms::Button^  EmergencyStop;
	private: System::Windows::Forms::Button^  button_teach;
	private: System::Windows::Forms::Button^  button_wheel;
	private: System::Windows::Forms::Button^  button_home;
	private: System::Windows::Forms::Timer^  RT_Timer;
	private: System::Windows::Forms::Button^  button_jog;
	private: System::Windows::Forms::Button^  button_MDI;
	private: System::Windows::Forms::Button^  button_memory;
	private: System::Windows::Forms::RichTextBox^  richTextBox_fileName;
	private: System::Windows::Forms::Button^  button_openFile;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog_openFile;
	private: System::Windows::Forms::RichTextBox^  richTextBox_fileContent;
	private: System::Windows::Forms::Label^  y_valueDisplay;
	private: System::Windows::Forms::Label^  z_valueDisplay;

	private: System::Windows::Forms::Label^  x_valueDisplay;
	private: System::Windows::Forms::Label^  y_label;
	private: System::Windows::Forms::Label^  z_label;
	private: System::Windows::Forms::Label^  x_label;
	private: System::Windows::Forms::Label^  label_NZ;
	private: System::Windows::Forms::Label^  label_PZ;
	private: System::Windows::Forms::Label^  label_NY;
	private: System::Windows::Forms::Label^  label_PY;
	private: System::Windows::Forms::Label^  label_NX;
	private: System::Windows::Forms::Label^  label_PX;
	private: System::Windows::Forms::Label^  label_INZ;
	private: System::Windows::Forms::Label^  label_HZ;
	private: System::Windows::Forms::Label^  label_INY;
	private: System::Windows::Forms::Label^  label_HY;
	private: System::Windows::Forms::Label^  label_INX;
	private: System::Windows::Forms::Label^  label_HX;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label_M01;

	private: System::Windows::Forms::Label^  label_ERR;
	private: System::Windows::Forms::Label^  label_PGM;
	private: System::Windows::Forms::Label^  label_M30;
	private: System::Windows::Forms::Label^  label_M00;
	private: System::Windows::Forms::Button^  button_coordTwoggle;
	private: System::Windows::Forms::Button^  button_save;
	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label_feedOverride = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->trackBar_feedOverride = (gcnew System::Windows::Forms::TrackBar());
			this->w_valueDisplay = (gcnew System::Windows::Forms::Label());
			this->v_valueDisplay = (gcnew System::Windows::Forms::Label());
			this->u_valueDisplay = (gcnew System::Windows::Forms::Label());
			this->w_label = (gcnew System::Windows::Forms::Label());
			this->v_label = (gcnew System::Windows::Forms::Label());
			this->u_label = (gcnew System::Windows::Forms::Label());
			this->button_m01 = (gcnew System::Windows::Forms::Button());
			this->button_fh = (gcnew System::Windows::Forms::Button());
			this->button_clr = (gcnew System::Windows::Forms::Button());
			this->button_speedx100 = (gcnew System::Windows::Forms::Button());
			this->button_speedx10 = (gcnew System::Windows::Forms::Button());
			this->button_speedx1 = (gcnew System::Windows::Forms::Button());
			this->button_zMinus = (gcnew System::Windows::Forms::Button());
			this->button_yMinus = (gcnew System::Windows::Forms::Button());
			this->button_xMinus = (gcnew System::Windows::Forms::Button());
			this->button_zPlus = (gcnew System::Windows::Forms::Button());
			this->button_xPlus = (gcnew System::Windows::Forms::Button());
			this->NRT_Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->button_yPlus = (gcnew System::Windows::Forms::Button());
			this->button_cycleStart = (gcnew System::Windows::Forms::Button());
			this->button_reset = (gcnew System::Windows::Forms::Button());
			this->EmergencyStop = (gcnew System::Windows::Forms::Button());
			this->button_teach = (gcnew System::Windows::Forms::Button());
			this->button_wheel = (gcnew System::Windows::Forms::Button());
			this->button_home = (gcnew System::Windows::Forms::Button());
			this->RT_Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->button_jog = (gcnew System::Windows::Forms::Button());
			this->button_MDI = (gcnew System::Windows::Forms::Button());
			this->button_memory = (gcnew System::Windows::Forms::Button());
			this->richTextBox_fileName = (gcnew System::Windows::Forms::RichTextBox());
			this->button_openFile = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_openFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->richTextBox_fileContent = (gcnew System::Windows::Forms::RichTextBox());
			this->y_valueDisplay = (gcnew System::Windows::Forms::Label());
			this->z_valueDisplay = (gcnew System::Windows::Forms::Label());
			this->x_valueDisplay = (gcnew System::Windows::Forms::Label());
			this->y_label = (gcnew System::Windows::Forms::Label());
			this->z_label = (gcnew System::Windows::Forms::Label());
			this->x_label = (gcnew System::Windows::Forms::Label());
			this->label_NZ = (gcnew System::Windows::Forms::Label());
			this->label_PZ = (gcnew System::Windows::Forms::Label());
			this->label_NY = (gcnew System::Windows::Forms::Label());
			this->label_PY = (gcnew System::Windows::Forms::Label());
			this->label_NX = (gcnew System::Windows::Forms::Label());
			this->label_PX = (gcnew System::Windows::Forms::Label());
			this->label_INZ = (gcnew System::Windows::Forms::Label());
			this->label_HZ = (gcnew System::Windows::Forms::Label());
			this->label_INY = (gcnew System::Windows::Forms::Label());
			this->label_HY = (gcnew System::Windows::Forms::Label());
			this->label_INX = (gcnew System::Windows::Forms::Label());
			this->label_HX = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label_M01 = (gcnew System::Windows::Forms::Label());
			this->label_ERR = (gcnew System::Windows::Forms::Label());
			this->label_PGM = (gcnew System::Windows::Forms::Label());
			this->label_M30 = (gcnew System::Windows::Forms::Label());
			this->label_M00 = (gcnew System::Windows::Forms::Label());
			this->button_coordTwoggle = (gcnew System::Windows::Forms::Button());
			this->button_save = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar_feedOverride))->BeginInit();
			this->SuspendLayout();
			// 
			// label_feedOverride
			// 
			this->label_feedOverride->AutoSize = true;
			this->label_feedOverride->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_feedOverride->Location = System::Drawing::Point(700, 308);
			this->label_feedOverride->Name = L"label_feedOverride";
			this->label_feedOverride->Size = System::Drawing::Size(34, 14);
			this->label_feedOverride->TabIndex = 123;
			this->label_feedOverride->Text = L"100%";
			// 
			// label16
			// 
			this->label16->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(544, 305);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(101, 19);
			this->label16->TabIndex = 122;
			this->label16->Text = L"Feed Overide";
			// 
			// trackBar_feedOverride
			// 
			this->trackBar_feedOverride->AutoSize = false;
			this->trackBar_feedOverride->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->trackBar_feedOverride->Location = System::Drawing::Point(546, 327);
			this->trackBar_feedOverride->Maximum = 200;
			this->trackBar_feedOverride->Name = L"trackBar_feedOverride";
			this->trackBar_feedOverride->Size = System::Drawing::Size(196, 45);
			this->trackBar_feedOverride->TabIndex = 70;
			this->trackBar_feedOverride->TickFrequency = 10;
			this->trackBar_feedOverride->Value = 100;
			this->trackBar_feedOverride->Scroll += gcnew System::EventHandler(this, &Form1::trackBar_feedOverride_Scroll);
			// 
			// w_valueDisplay
			// 
			this->w_valueDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->w_valueDisplay->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->w_valueDisplay->Location = System::Drawing::Point(108, 390);
			this->w_valueDisplay->Name = L"w_valueDisplay";
			this->w_valueDisplay->Size = System::Drawing::Size(165, 30);
			this->w_valueDisplay->TabIndex = 121;
			this->w_valueDisplay->Text = L"0.000";
			// 
			// v_valueDisplay
			// 
			this->v_valueDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->v_valueDisplay->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->v_valueDisplay->Location = System::Drawing::Point(108, 350);
			this->v_valueDisplay->Name = L"v_valueDisplay";
			this->v_valueDisplay->Size = System::Drawing::Size(165, 30);
			this->v_valueDisplay->TabIndex = 120;
			this->v_valueDisplay->Text = L"90.000";
			// 
			// u_valueDisplay
			// 
			this->u_valueDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->u_valueDisplay->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->u_valueDisplay->Location = System::Drawing::Point(108, 310);
			this->u_valueDisplay->Name = L"u_valueDisplay";
			this->u_valueDisplay->Size = System::Drawing::Size(165, 30);
			this->u_valueDisplay->TabIndex = 119;
			this->u_valueDisplay->Text = L"0.000";
			// 
			// w_label
			// 
			this->w_label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->w_label->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->w_label->Location = System::Drawing::Point(53, 390);
			this->w_label->Name = L"w_label";
			this->w_label->Size = System::Drawing::Size(30, 30);
			this->w_label->TabIndex = 118;
			this->w_label->Text = L"W";
			this->w_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// v_label
			// 
			this->v_label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->v_label->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->v_label->Location = System::Drawing::Point(53, 350);
			this->v_label->Name = L"v_label";
			this->v_label->Size = System::Drawing::Size(30, 30);
			this->v_label->TabIndex = 117;
			this->v_label->Text = L"V";
			this->v_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// u_label
			// 
			this->u_label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->u_label->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->u_label->Location = System::Drawing::Point(53, 310);
			this->u_label->Name = L"u_label";
			this->u_label->Size = System::Drawing::Size(30, 30);
			this->u_label->TabIndex = 116;
			this->u_label->Text = L"U";
			this->u_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_m01
			// 
			this->button_m01->BackColor = System::Drawing::Color::AliceBlue;
			this->button_m01->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_m01->Location = System::Drawing::Point(472, 366);
			this->button_m01->Name = L"button_m01";
			this->button_m01->Size = System::Drawing::Size(40, 30);
			this->button_m01->TabIndex = 115;
			this->button_m01->Text = L"M01";
			this->button_m01->UseVisualStyleBackColor = false;
			this->button_m01->Click += gcnew System::EventHandler(this, &Form1::button_m01_Click);
			// 
			// button_fh
			// 
			this->button_fh->BackColor = System::Drawing::Color::AliceBlue;
			this->button_fh->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_fh->Location = System::Drawing::Point(472, 405);
			this->button_fh->Name = L"button_fh";
			this->button_fh->Size = System::Drawing::Size(40, 30);
			this->button_fh->TabIndex = 114;
			this->button_fh->Text = L"FH";
			this->button_fh->UseVisualStyleBackColor = false;
			this->button_fh->Click += gcnew System::EventHandler(this, &Form1::button_fh_Click);
			// 
			// button_clr
			// 
			this->button_clr->BackColor = System::Drawing::Color::AliceBlue;
			this->button_clr->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_clr->Location = System::Drawing::Point(472, 326);
			this->button_clr->Name = L"button_clr";
			this->button_clr->Size = System::Drawing::Size(40, 30);
			this->button_clr->TabIndex = 113;
			this->button_clr->Text = L"CLR";
			this->button_clr->UseVisualStyleBackColor = false;
			this->button_clr->Click += gcnew System::EventHandler(this, &Form1::button_clr_Click);
			// 
			// button_speedx100
			// 
			this->button_speedx100->BackColor = System::Drawing::Color::AliceBlue;
			this->button_speedx100->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_speedx100->Location = System::Drawing::Point(426, 406);
			this->button_speedx100->Name = L"button_speedx100";
			this->button_speedx100->Size = System::Drawing::Size(40, 30);
			this->button_speedx100->TabIndex = 112;
			this->button_speedx100->Text = L"X100";
			this->button_speedx100->UseVisualStyleBackColor = false;
			this->button_speedx100->Click += gcnew System::EventHandler(this, &Form1::button_speedx100_Click);
			// 
			// button_speedx10
			// 
			this->button_speedx10->BackColor = System::Drawing::Color::AliceBlue;
			this->button_speedx10->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_speedx10->Location = System::Drawing::Point(426, 366);
			this->button_speedx10->Name = L"button_speedx10";
			this->button_speedx10->Size = System::Drawing::Size(40, 30);
			this->button_speedx10->TabIndex = 111;
			this->button_speedx10->Text = L"X10";
			this->button_speedx10->UseVisualStyleBackColor = false;
			this->button_speedx10->Click += gcnew System::EventHandler(this, &Form1::button_speedx10_Click);
			// 
			// button_speedx1
			// 
			this->button_speedx1->BackColor = System::Drawing::Color::AliceBlue;
			this->button_speedx1->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_speedx1->Location = System::Drawing::Point(426, 326);
			this->button_speedx1->Name = L"button_speedx1";
			this->button_speedx1->Size = System::Drawing::Size(40, 30);
			this->button_speedx1->TabIndex = 110;
			this->button_speedx1->Text = L"X1";
			this->button_speedx1->UseVisualStyleBackColor = false;
			this->button_speedx1->Click += gcnew System::EventHandler(this, &Form1::button_speedx1_Click);
			// 
			// button_zMinus
			// 
			this->button_zMinus->BackColor = System::Drawing::Color::LightCyan;
			this->button_zMinus->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_zMinus->Location = System::Drawing::Point(315, 406);
			this->button_zMinus->Name = L"button_zMinus";
			this->button_zMinus->Size = System::Drawing::Size(40, 30);
			this->button_zMinus->TabIndex = 109;
			this->button_zMinus->Text = L"Z-";
			this->button_zMinus->UseVisualStyleBackColor = false;
			this->button_zMinus->Click += gcnew System::EventHandler(this, &Form1::button_zMinus_Click);
			// 
			// button_yMinus
			// 
			this->button_yMinus->BackColor = System::Drawing::Color::LightCyan;
			this->button_yMinus->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_yMinus->Location = System::Drawing::Point(315, 366);
			this->button_yMinus->Name = L"button_yMinus";
			this->button_yMinus->Size = System::Drawing::Size(40, 30);
			this->button_yMinus->TabIndex = 108;
			this->button_yMinus->Text = L"Y-";
			this->button_yMinus->UseVisualStyleBackColor = false;
			this->button_yMinus->Click += gcnew System::EventHandler(this, &Form1::button_yMinus_Click);
			// 
			// button_xMinus
			// 
			this->button_xMinus->BackColor = System::Drawing::Color::LightCyan;
			this->button_xMinus->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_xMinus->Location = System::Drawing::Point(315, 326);
			this->button_xMinus->Name = L"button_xMinus";
			this->button_xMinus->Size = System::Drawing::Size(40, 30);
			this->button_xMinus->TabIndex = 107;
			this->button_xMinus->Text = L"X-";
			this->button_xMinus->UseVisualStyleBackColor = false;
			this->button_xMinus->Click += gcnew System::EventHandler(this, &Form1::button_xMinus_Click);
			// 
			// button_zPlus
			// 
			this->button_zPlus->BackColor = System::Drawing::Color::LightCyan;
			this->button_zPlus->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_zPlus->Location = System::Drawing::Point(361, 406);
			this->button_zPlus->Name = L"button_zPlus";
			this->button_zPlus->Size = System::Drawing::Size(40, 30);
			this->button_zPlus->TabIndex = 106;
			this->button_zPlus->Text = L"Z+";
			this->button_zPlus->UseVisualStyleBackColor = false;
			this->button_zPlus->Click += gcnew System::EventHandler(this, &Form1::button_zPlus_Click);
			// 
			// button_xPlus
			// 
			this->button_xPlus->BackColor = System::Drawing::Color::LightCyan;
			this->button_xPlus->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_xPlus->Location = System::Drawing::Point(361, 326);
			this->button_xPlus->Name = L"button_xPlus";
			this->button_xPlus->Size = System::Drawing::Size(40, 30);
			this->button_xPlus->TabIndex = 104;
			this->button_xPlus->Text = L"X+";
			this->button_xPlus->UseVisualStyleBackColor = false;
			this->button_xPlus->Click += gcnew System::EventHandler(this, &Form1::button_xPlus_Click);
			// 
			// NRT_Timer
			// 
			this->NRT_Timer->Enabled = true;
			this->NRT_Timer->Interval = 10;
			this->NRT_Timer->Tick += gcnew System::EventHandler(this, &Form1::NRT_Timer_Tick);
			// 
			// button_yPlus
			// 
			this->button_yPlus->BackColor = System::Drawing::Color::LightCyan;
			this->button_yPlus->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_yPlus->Location = System::Drawing::Point(361, 366);
			this->button_yPlus->Name = L"button_yPlus";
			this->button_yPlus->Size = System::Drawing::Size(40, 30);
			this->button_yPlus->TabIndex = 105;
			this->button_yPlus->Text = L"Y+";
			this->button_yPlus->UseVisualStyleBackColor = false;
			this->button_yPlus->Click += gcnew System::EventHandler(this, &Form1::button_yPlus_Click);
			// 
			// button_cycleStart
			// 
			this->button_cycleStart->BackColor = System::Drawing::Color::White;
			this->button_cycleStart->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_cycleStart->Location = System::Drawing::Point(660, 378);
			this->button_cycleStart->Name = L"button_cycleStart";
			this->button_cycleStart->Size = System::Drawing::Size(87, 61);
			this->button_cycleStart->TabIndex = 103;
			this->button_cycleStart->Text = L"CYCLE START";
			this->button_cycleStart->UseVisualStyleBackColor = false;
			this->button_cycleStart->Click += gcnew System::EventHandler(this, &Form1::button_cycleStart_Click);
			// 
			// button_reset
			// 
			this->button_reset->BackColor = System::Drawing::Color::White;
			this->button_reset->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_reset->Location = System::Drawing::Point(546, 378);
			this->button_reset->Name = L"button_reset";
			this->button_reset->Size = System::Drawing::Size(87, 61);
			this->button_reset->TabIndex = 102;
			this->button_reset->Text = L"RESET";
			this->button_reset->UseVisualStyleBackColor = false;
			this->button_reset->Click += gcnew System::EventHandler(this, &Form1::button_reset_Click);
			// 
			// EmergencyStop
			// 
			this->EmergencyStop->BackColor = System::Drawing::Color::Red;
			this->EmergencyStop->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EmergencyStop->Location = System::Drawing::Point(585, 456);
			this->EmergencyStop->Name = L"EmergencyStop";
			this->EmergencyStop->Size = System::Drawing::Size(160, 60);
			this->EmergencyStop->TabIndex = 101;
			this->EmergencyStop->Text = L"EMERGENCY STOP";
			this->EmergencyStop->UseVisualStyleBackColor = false;
			this->EmergencyStop->Click += gcnew System::EventHandler(this, &Form1::EmergencyStop_Click);
			// 
			// button_teach
			// 
			this->button_teach->BackColor = System::Drawing::Color::SteelBlue;
			this->button_teach->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_teach->Location = System::Drawing::Point(451, 456);
			this->button_teach->Name = L"button_teach";
			this->button_teach->Size = System::Drawing::Size(70, 60);
			this->button_teach->TabIndex = 100;
			this->button_teach->Text = L"TEACH";
			this->button_teach->UseVisualStyleBackColor = false;
			this->button_teach->Click += gcnew System::EventHandler(this, &Form1::button_teach_Click);
			// 
			// button_wheel
			// 
			this->button_wheel->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button_wheel->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_wheel->Location = System::Drawing::Point(371, 456);
			this->button_wheel->Name = L"button_wheel";
			this->button_wheel->Size = System::Drawing::Size(70, 60);
			this->button_wheel->TabIndex = 99;
			this->button_wheel->Text = L"WHEEL";
			this->button_wheel->UseVisualStyleBackColor = false;
			this->button_wheel->Click += gcnew System::EventHandler(this, &Form1::button_wheel_Click);
			// 
			// button_home
			// 
			this->button_home->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button_home->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_home->Location = System::Drawing::Point(291, 456);
			this->button_home->Name = L"button_home";
			this->button_home->Size = System::Drawing::Size(70, 60);
			this->button_home->TabIndex = 98;
			this->button_home->Text = L"HOME";
			this->button_home->UseVisualStyleBackColor = false;
			this->button_home->Click += gcnew System::EventHandler(this, &Form1::button_home_Click);
			// 
			// RT_Timer
			// 
			this->RT_Timer->Enabled = true;
			this->RT_Timer->Interval = 20;
			this->RT_Timer->Tick += gcnew System::EventHandler(this, &Form1::RT_Timer_Tick);
			// 
			// button_jog
			// 
			this->button_jog->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button_jog->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_jog->Location = System::Drawing::Point(211, 456);
			this->button_jog->Name = L"button_jog";
			this->button_jog->Size = System::Drawing::Size(70, 60);
			this->button_jog->TabIndex = 97;
			this->button_jog->Text = L"JOG";
			this->button_jog->UseVisualStyleBackColor = false;
			this->button_jog->Click += gcnew System::EventHandler(this, &Form1::button_jog_Click);
			// 
			// button_MDI
			// 
			this->button_MDI->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button_MDI->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_MDI->Location = System::Drawing::Point(131, 456);
			this->button_MDI->Name = L"button_MDI";
			this->button_MDI->Size = System::Drawing::Size(70, 60);
			this->button_MDI->TabIndex = 96;
			this->button_MDI->Text = L"MDI";
			this->button_MDI->UseVisualStyleBackColor = false;
			this->button_MDI->Click += gcnew System::EventHandler(this, &Form1::button_MDI_Click);
			// 
			// button_memory
			// 
			this->button_memory->BackColor = System::Drawing::Color::SteelBlue;
			this->button_memory->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_memory->Location = System::Drawing::Point(51, 456);
			this->button_memory->Name = L"button_memory";
			this->button_memory->Size = System::Drawing::Size(70, 60);
			this->button_memory->TabIndex = 95;
			this->button_memory->Text = L"MEM";
			this->button_memory->UseVisualStyleBackColor = false;
			this->button_memory->Click += gcnew System::EventHandler(this, &Form1::button_memory_Click);
			// 
			// richTextBox_fileName
			// 
			this->richTextBox_fileName->Location = System::Drawing::Point(469, 243);
			this->richTextBox_fileName->Name = L"richTextBox_fileName";
			this->richTextBox_fileName->Size = System::Drawing::Size(280, 30);
			this->richTextBox_fileName->TabIndex = 94;
			this->richTextBox_fileName->Text = L"";
			// 
			// button_openFile
			// 
			this->button_openFile->BackColor = System::Drawing::Color::White;
			this->button_openFile->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_openFile->Location = System::Drawing::Point(391, 243);
			this->button_openFile->Name = L"button_openFile";
			this->button_openFile->Size = System::Drawing::Size(60, 30);
			this->button_openFile->TabIndex = 93;
			this->button_openFile->Text = L"Open";
			this->button_openFile->UseVisualStyleBackColor = false;
			this->button_openFile->Click += gcnew System::EventHandler(this, &Form1::button_openFile_Click);
			// 
			// openFileDialog_openFile
			// 
			this->openFileDialog_openFile->FileName = L"openFileDialog";
			// 
			// richTextBox_fileContent
			// 
			this->richTextBox_fileContent->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox_fileContent->Location = System::Drawing::Point(391, 106);
			this->richTextBox_fileContent->Name = L"richTextBox_fileContent";
			this->richTextBox_fileContent->Size = System::Drawing::Size(360, 120);
			this->richTextBox_fileContent->TabIndex = 92;
			this->richTextBox_fileContent->Text = L"";
			// 
			// y_valueDisplay
			// 
			this->y_valueDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->y_valueDisplay->Font = (gcnew System::Drawing::Font(L"Calibri", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->y_valueDisplay->Location = System::Drawing::Point(131, 166);
			this->y_valueDisplay->Name = L"y_valueDisplay";
			this->y_valueDisplay->Size = System::Drawing::Size(200, 50);
			this->y_valueDisplay->TabIndex = 91;
			this->y_valueDisplay->Text = L"75.000";
			// 
			// z_valueDisplay
			// 
			this->z_valueDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->z_valueDisplay->Font = (gcnew System::Drawing::Font(L"Calibri", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->z_valueDisplay->Location = System::Drawing::Point(131, 226);
			this->z_valueDisplay->Name = L"z_valueDisplay";
			this->z_valueDisplay->Size = System::Drawing::Size(200, 50);
			this->z_valueDisplay->TabIndex = 90;
			this->z_valueDisplay->Text = L"0.000";
			// 
			// x_valueDisplay
			// 
			this->x_valueDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->x_valueDisplay->Font = (gcnew System::Drawing::Font(L"Calibri", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->x_valueDisplay->Location = System::Drawing::Point(131, 106);
			this->x_valueDisplay->Name = L"x_valueDisplay";
			this->x_valueDisplay->Size = System::Drawing::Size(200, 50);
			this->x_valueDisplay->TabIndex = 89;
			this->x_valueDisplay->Text = L"75.000";
			// 
			// y_label
			// 
			this->y_label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->y_label->Font = (gcnew System::Drawing::Font(L"Calibri", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->y_label->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->y_label->Location = System::Drawing::Point(51, 166);
			this->y_label->Name = L"y_label";
			this->y_label->Size = System::Drawing::Size(50, 50);
			this->y_label->TabIndex = 88;
			this->y_label->Text = L"Y";
			this->y_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// z_label
			// 
			this->z_label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->z_label->Font = (gcnew System::Drawing::Font(L"Calibri", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->z_label->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->z_label->Location = System::Drawing::Point(51, 226);
			this->z_label->Name = L"z_label";
			this->z_label->Size = System::Drawing::Size(50, 50);
			this->z_label->TabIndex = 87;
			this->z_label->Text = L"Z";
			this->z_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// x_label
			// 
			this->x_label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->x_label->Font = (gcnew System::Drawing::Font(L"Calibri", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->x_label->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->x_label->Location = System::Drawing::Point(51, 106);
			this->x_label->Name = L"x_label";
			this->x_label->Size = System::Drawing::Size(50, 50);
			this->x_label->TabIndex = 86;
			this->x_label->Text = L"X";
			this->x_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_NZ
			// 
			this->label_NZ->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_NZ->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_NZ->Location = System::Drawing::Point(691, 46);
			this->label_NZ->Name = L"label_NZ";
			this->label_NZ->Size = System::Drawing::Size(60, 30);
			this->label_NZ->TabIndex = 85;
			this->label_NZ->Text = L"NZ";
			this->label_NZ->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_PZ
			// 
			this->label_PZ->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_PZ->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_PZ->Location = System::Drawing::Point(691, 16);
			this->label_PZ->Name = L"label_PZ";
			this->label_PZ->Size = System::Drawing::Size(60, 30);
			this->label_PZ->TabIndex = 84;
			this->label_PZ->Text = L"PZ";
			this->label_PZ->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_NY
			// 
			this->label_NY->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_NY->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_NY->Location = System::Drawing::Point(631, 46);
			this->label_NY->Name = L"label_NY";
			this->label_NY->Size = System::Drawing::Size(60, 30);
			this->label_NY->TabIndex = 83;
			this->label_NY->Text = L"NY";
			this->label_NY->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_PY
			// 
			this->label_PY->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_PY->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_PY->Location = System::Drawing::Point(631, 16);
			this->label_PY->Name = L"label_PY";
			this->label_PY->Size = System::Drawing::Size(60, 30);
			this->label_PY->TabIndex = 82;
			this->label_PY->Text = L"PY";
			this->label_PY->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_NX
			// 
			this->label_NX->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_NX->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_NX->Location = System::Drawing::Point(571, 46);
			this->label_NX->Name = L"label_NX";
			this->label_NX->Size = System::Drawing::Size(60, 30);
			this->label_NX->TabIndex = 81;
			this->label_NX->Text = L"NX";
			this->label_NX->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_PX
			// 
			this->label_PX->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_PX->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_PX->Location = System::Drawing::Point(571, 16);
			this->label_PX->Name = L"label_PX";
			this->label_PX->Size = System::Drawing::Size(60, 30);
			this->label_PX->TabIndex = 80;
			this->label_PX->Text = L"PX";
			this->label_PX->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_INZ
			// 
			this->label_INZ->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_INZ->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_INZ->Location = System::Drawing::Point(511, 46);
			this->label_INZ->Name = L"label_INZ";
			this->label_INZ->Size = System::Drawing::Size(60, 30);
			this->label_INZ->TabIndex = 79;
			this->label_INZ->Text = L"INZ";
			this->label_INZ->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_HZ
			// 
			this->label_HZ->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_HZ->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_HZ->Location = System::Drawing::Point(511, 16);
			this->label_HZ->Name = L"label_HZ";
			this->label_HZ->Size = System::Drawing::Size(60, 30);
			this->label_HZ->TabIndex = 78;
			this->label_HZ->Text = L"HZ";
			this->label_HZ->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_INY
			// 
			this->label_INY->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_INY->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_INY->Location = System::Drawing::Point(451, 46);
			this->label_INY->Name = L"label_INY";
			this->label_INY->Size = System::Drawing::Size(60, 30);
			this->label_INY->TabIndex = 77;
			this->label_INY->Text = L"INY";
			this->label_INY->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_HY
			// 
			this->label_HY->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_HY->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_HY->Location = System::Drawing::Point(451, 16);
			this->label_HY->Name = L"label_HY";
			this->label_HY->Size = System::Drawing::Size(60, 30);
			this->label_HY->TabIndex = 76;
			this->label_HY->Text = L"HY";
			this->label_HY->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_INX
			// 
			this->label_INX->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_INX->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_INX->Location = System::Drawing::Point(391, 46);
			this->label_INX->Name = L"label_INX";
			this->label_INX->Size = System::Drawing::Size(60, 30);
			this->label_INX->TabIndex = 75;
			this->label_INX->Text = L"INX";
			this->label_INX->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_HX
			// 
			this->label_HX->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_HX->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_HX->Location = System::Drawing::Point(391, 16);
			this->label_HX->Name = L"label_HX";
			this->label_HX->Size = System::Drawing::Size(60, 30);
			this->label_HX->TabIndex = 74;
			this->label_HX->Text = L"HX";
			this->label_HX->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Location = System::Drawing::Point(331, 46);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(60, 30);
			this->label6->TabIndex = 73;
			// 
			// label7
			// 
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label7->Location = System::Drawing::Point(331, 16);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(60, 30);
			this->label7->TabIndex = 72;
			// 
			// label8
			// 
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->Location = System::Drawing::Point(271, 46);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(60, 30);
			this->label8->TabIndex = 71;
			// 
			// label_M01
			// 
			this->label_M01->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_M01->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_M01->Location = System::Drawing::Point(271, 16);
			this->label_M01->Name = L"label_M01";
			this->label_M01->Size = System::Drawing::Size(60, 30);
			this->label_M01->TabIndex = 69;
			this->label_M01->Text = L"M01";
			this->label_M01->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_ERR
			// 
			this->label_ERR->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_ERR->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_ERR->Location = System::Drawing::Point(211, 46);
			this->label_ERR->Name = L"label_ERR";
			this->label_ERR->Size = System::Drawing::Size(60, 30);
			this->label_ERR->TabIndex = 68;
			this->label_ERR->Text = L"ERR";
			this->label_ERR->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_PGM
			// 
			this->label_PGM->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_PGM->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_PGM->Location = System::Drawing::Point(211, 16);
			this->label_PGM->Name = L"label_PGM";
			this->label_PGM->Size = System::Drawing::Size(60, 30);
			this->label_PGM->TabIndex = 67;
			this->label_PGM->Text = L"PGM";
			this->label_PGM->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_M30
			// 
			this->label_M30->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_M30->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F));
			this->label_M30->Location = System::Drawing::Point(151, 46);
			this->label_M30->Name = L"label_M30";
			this->label_M30->Size = System::Drawing::Size(60, 30);
			this->label_M30->TabIndex = 66;
			this->label_M30->Text = L"M30";
			this->label_M30->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_M00
			// 
			this->label_M00->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_M00->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_M00->Location = System::Drawing::Point(151, 16);
			this->label_M00->Name = L"label_M00";
			this->label_M00->Size = System::Drawing::Size(60, 30);
			this->label_M00->TabIndex = 65;
			this->label_M00->Text = L"M00";
			this->label_M00->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_coordTwoggle
			// 
			this->button_coordTwoggle->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_coordTwoggle->Location = System::Drawing::Point(321, 293);
			this->button_coordTwoggle->Name = L"button_coordTwoggle";
			this->button_coordTwoggle->Size = System::Drawing::Size(75, 27);
			this->button_coordTwoggle->TabIndex = 124;
			this->button_coordTwoggle->Text = L"UVW Mode";
			this->button_coordTwoggle->UseVisualStyleBackColor = true;
			this->button_coordTwoggle->Click += gcnew System::EventHandler(this, &Form1::button_coordTwoggle_Click);
			// 
			// button_save
			// 
			this->button_save->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_save->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_save->Location = System::Drawing::Point(431, 293);
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(75, 27);
			this->button_save->TabIndex = 125;
			this->button_save->Text = L"Save point";
			this->button_save->UseVisualStyleBackColor = true;
			this->button_save->Click += gcnew System::EventHandler(this, &Form1::button_save_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(525, 519);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(254, 23);
			this->label1->TabIndex = 126;
			this->label1->Text = L"©2015 Philip Lin All Rights Reserved";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::GhostWhite;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(800, 544);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_save);
			this->Controls->Add(this->button_coordTwoggle);
			this->Controls->Add(this->label_feedOverride);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->trackBar_feedOverride);
			this->Controls->Add(this->w_valueDisplay);
			this->Controls->Add(this->v_valueDisplay);
			this->Controls->Add(this->u_valueDisplay);
			this->Controls->Add(this->w_label);
			this->Controls->Add(this->v_label);
			this->Controls->Add(this->u_label);
			this->Controls->Add(this->button_m01);
			this->Controls->Add(this->button_fh);
			this->Controls->Add(this->button_clr);
			this->Controls->Add(this->button_speedx100);
			this->Controls->Add(this->button_speedx10);
			this->Controls->Add(this->button_speedx1);
			this->Controls->Add(this->button_zMinus);
			this->Controls->Add(this->button_yMinus);
			this->Controls->Add(this->button_xMinus);
			this->Controls->Add(this->button_zPlus);
			this->Controls->Add(this->button_xPlus);
			this->Controls->Add(this->button_yPlus);
			this->Controls->Add(this->button_cycleStart);
			this->Controls->Add(this->button_reset);
			this->Controls->Add(this->EmergencyStop);
			this->Controls->Add(this->button_teach);
			this->Controls->Add(this->button_wheel);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->button_jog);
			this->Controls->Add(this->button_MDI);
			this->Controls->Add(this->button_memory);
			this->Controls->Add(this->richTextBox_fileName);
			this->Controls->Add(this->button_openFile);
			this->Controls->Add(this->richTextBox_fileContent);
			this->Controls->Add(this->y_valueDisplay);
			this->Controls->Add(this->z_valueDisplay);
			this->Controls->Add(this->x_valueDisplay);
			this->Controls->Add(this->y_label);
			this->Controls->Add(this->z_label);
			this->Controls->Add(this->x_label);
			this->Controls->Add(this->label_NZ);
			this->Controls->Add(this->label_PZ);
			this->Controls->Add(this->label_NY);
			this->Controls->Add(this->label_PY);
			this->Controls->Add(this->label_NX);
			this->Controls->Add(this->label_PX);
			this->Controls->Add(this->label_INZ);
			this->Controls->Add(this->label_HZ);
			this->Controls->Add(this->label_INY);
			this->Controls->Add(this->label_HY);
			this->Controls->Add(this->label_INX);
			this->Controls->Add(this->label_HX);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label_M01);
			this->Controls->Add(this->label_ERR);
			this->Controls->Add(this->label_PGM);
			this->Controls->Add(this->label_M30);
			this->Controls->Add(this->label_M00);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Form1";
			this->Text = L"My iCNC";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar_feedOverride))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
		 {          //******************************initiate CNC system**************************//
			 cncDataPtr= &cncData;
			 sysDataPtr = &cncDataPtr->sysData;
			 mmiDataPtr = &cncDataPtr->mmiData;
			 decDataPtr = &cncDataPtr->decData;
			 intpDataPtr = &cncDataPtr->intpData;
			 linkDataPtr = &cncDataPtr->linkData;
			 mmiDataPtr->opMode = MEM_MODE;
			 
			
			 cncInit(cncDataPtr);

#if HD_TIMER
			 // init motion card
			 initMotionCard(HOME_U_POSITION, HOME_V_POSITION, HOME_W_POSITION, REAL_SAMPLING_TIME, Timer_ISR_Function);
			 // enable timer
			 enableHDTimer(REAL_SAMPLING_TIME);	
			 RT_Timer->Enabled	= false;
			 NRT_Timer->Enabled	= true;
#else
			 RT_Timer->Interval = REAL_SAMPLING_TIME;
			 RT_Timer->Enabled	= true;
			 NRT_Timer->Enabled	= true;
#endif
		 }

private: System::Void NRT_Timer_Tick(System::Object^  sender, System::EventArgs^  e) // timers are countinuous
		 {
			 cncNrtCtl(cncDataPtr);
			 display();
		 }
private: System::Void RT_Timer_Tick(System::Object^  sender, System::EventArgs^  e)
		 {
			 cncRtCtl(cncDataPtr);
		 }
private: System::Void button_openFile_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
			 if (cncDataPtr->mmiData.opMode == MEM_MODE)//要在MEM Mode才會被處理
			 {
				 openFileDialog_openFile->InitialDirectory = "" ;                              //default directory for file ..\\ means the previous layer
				 openFileDialog_openFile->Filter = "文字檔(*.txt)|*.txt|所有檔案(*.)|*.*" ;    //displayed format filter | actual format filter
				 openFileDialog_openFile->FilterIndex = 2 ;                                    //default filter conditions
				 openFileDialog_openFile->DefaultExt = "*.txt" ;                               //set default as text file format
				 openFileDialog_openFile->FileName = "";                                       //clears the previous file directory
				 openFileDialog_openFile->RestoreDirectory = true;

				 if (openFileDialog_openFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 richTextBox_fileName->Text = openFileDialog_openFile->FileName ;
					 richTextBox_fileContent->LoadFile(openFileDialog_openFile->FileName , RichTextBoxStreamType::PlainText) ;	
				 }

			 }
			 else
			 {
				 MessageBox::Show("Openfile only works in MEM MODE!!","Mode Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;
			 }

		}
private: System::Void button_cycleStart_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (intpDataPtr->intpState == INTP_DWELL_TIME)
			 {
				 mmiDataPtr->mOne = false;
				 intpDataPtr->mzero = false;
				 intpDataPtr->intpState = INTP_IDLE;
			 }
			 else
			 {
				 if (richTextBox_fileContent->TextLength !=0)
				 {
					 richTextBox_fileContent->SaveFile("../TempNcCode/ncfile.txt",RichTextBoxStreamType::PlainText);
					 cncDataPtr->mmiData.fileValid = true;
					 cncDataPtr->mmiData.commence  = false;
				 }
				 if (cncDataPtr->mmiData.opMode == HOME_MODE)
				 {
					 FILE* jogPtr;
					 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
					 fprintf(jogPtr,"N100 G00 G90 U0 V90 W0\nM30");
					 fclose(jogPtr);
					 cncDataPtr->mmiData.homeValid = true;
				 }
			 }
		 }
//**********************************************************************************************************
// MODE BUTTONS // MODE BUTTONS // MODE BUTTONS // MODE BUTTONS // MODE BUTTONS// MODE BUTTONS// MODE BUTTONS
//**********************************************************************************************************
private: System::Void button_memory_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (mmiDataPtr->opMode != MEM_MODE)
			 {
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 mmiDataPtr->opMode = MEM_MODE;
				 modeDisplayReset();
				 button_memory->BackColor = System::Drawing::Color::SteelBlue;
				 richTextBox_fileContent->ReadOnly = false;
				 memDisplayReset();
				 jogDisplayReset();
			 }
		 }
private: System::Void button_MDI_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (mmiDataPtr->opMode != MDI_MODE)
			 {
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 mmiDataPtr->opMode = MDI_MODE;
				 modeDisplayReset();
				 button_MDI->BackColor = System::Drawing::Color::SteelBlue;			 
				 richTextBox_fileContent->ReadOnly = false;
				 mmiDataPtr->commence = true;
				 memDisplayReset();
				 jogDisplayReset();
			 }

		 }
private: System::Void button_jog_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (mmiDataPtr->opMode != JOG_MODE)
			 {
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 mmiDataPtr->opMode = JOG_MODE;
				 modeDisplayReset();
				 button_jog->BackColor = System::Drawing::Color::SteelBlue;
				 richTextBox_fileContent->ReadOnly = true;
				 memDisplayReset();
				 jogDisplayReset();
			 }
		 }
private: System::Void button_home_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (mmiDataPtr->opMode != HOME_MODE)
			 {
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 cncDataPtr->mmiData.jogValid = false;
				 mmiDataPtr->opMode = HOME_MODE;
				 modeDisplayReset();
				 button_home->BackColor = System::Drawing::Color::SteelBlue;

				 richTextBox_fileContent->ReadOnly = true;

				 memDisplayReset();
				 jogDisplayReset();
			 }
		 }
private: System::Void button_wheel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (mmiDataPtr->opMode != WHEEL_MODE)
			 {
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 mmiDataPtr->opMode = WHEEL_MODE;
				 mmiDataPtr->wheelMultiple = 0.001;
				 wheelDisplayReset();
				 button_speedx1->BackColor = System::Drawing::Color::SteelBlue;
				 modeDisplayReset();
				 button_wheel->BackColor = System::Drawing::Color::SteelBlue;
				 richTextBox_fileContent->ReadOnly = true;
				 memDisplayReset();
				 jogDisplayReset();
			 }
		 }
private: System::Void button_teach_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (button_teach->BackColor == System::Drawing::Color::SteelBlue)
			 {
				 button_teach->BackColor = System::Drawing::SystemColors::MenuHighlight;
				 button_save->Enabled = false;
			 }
			 else
			 {
				 button_teach->BackColor = System::Drawing::Color::SteelBlue;
				 button_save->Enabled = true;
			 }
			
		 }
//**************************************************************************************************
//  Jog Buttons  //  Jog Buttons  //  Jog Buttons  //  Jog Buttons  //  Jog Buttons  //  Jog Buttons
//**************************************************************************************************
private: System::Void button_coordTwoggle_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 if (mmiDataPtr->opMode == JOG_MODE)
			 {
				 cncDataPtr->mmiData.jogValid = false;
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 for(int i = 0 ; i < 3 ; i++)
				 {
					 mmiDataPtr->jogDirection[i] =0;
				 }
				 jogDisplayReset();
				 mmiDataPtr->jogCartesian = !mmiDataPtr->jogCartesian;
				 if(mmiDataPtr->jogCartesian == true)
				 {
					 button_xPlus  ->Text = "X+";
					 button_xMinus ->Text = "X-";
					 button_yPlus  ->Text = "Y+";
					 button_yMinus ->Text = "Y-";
					 button_zPlus  ->Text = "Z+";
					 button_zMinus ->Text = "Z-";
					 button_coordTwoggle ->Text = "UVW Mode";
				 }
				 else
				 {
					 button_xPlus ->Text = "U+";
					 button_xMinus ->Text = "U-";
					 button_yPlus ->Text = "V+";
					 button_yMinus ->Text = "V-";
					 button_zPlus ->Text = "W+";
					 button_zMinus ->Text = "W-";
					 button_coordTwoggle ->Text = "XYZ Mode";
				 }
			 }//if in jog mode
			 else
			 {
				 MessageBox::Show("Please select jog mode!" , "Mode Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;
			 }//if not in jog mode
		 }//twoggle xyz uvw button click
private: System::Void button_xPlus_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (mmiDataPtr->opMode == JOG_MODE)
			 {
				 if (cncDataPtr->mmiData.jogCartesian == true)
				 {
					 if( mmiDataPtr->jogDirection[0] == 1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[0] = 0;
						 button_xPlus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if ( mmiDataPtr->jogDirection[0] == -1 ||							  
							  mmiDataPtr->jogDirection[1] == 1 ||mmiDataPtr->jogDirection[1]==-1||
							  mmiDataPtr->jogDirection[2] == 1 ||mmiDataPtr->jogDirection[2]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[0] = 1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G01 G91 X300 Y0 Z0\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_xPlus->BackColor = Color::SteelBlue;						 
					 }
				 }//if in Cartesian coordinates
				 else
				 {
					 if( mmiDataPtr->jogDirection[0] == 1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[0] = 0;
						 button_xPlus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if ( mmiDataPtr->jogDirection[0] == -1||
							  mmiDataPtr->jogDirection[1] == 1 ||mmiDataPtr->jogDirection[1]==-1||
							  mmiDataPtr->jogDirection[2] == 1 ||mmiDataPtr->jogDirection[2]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[0] = 1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G00 G91 U30000 V0 W0\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_xPlus->BackColor = Color::SteelBlue;
					 }
				 }//if x+ Cartesian false
			 }//if in jog mode
			 else if (cncDataPtr->mmiData.opMode == WHEEL_MODE)
			 {
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 FILE* wheelPtr;
				 wheelPtr = fopen("../TempNcCode/ncfile.txt","w");
				 fprintf(wheelPtr,"N100 G01 G91 X%f Y0 Z0 \nM30",mmiDataPtr->wheelMultiple);
				 fclose(wheelPtr);
				 mmiDataPtr->wheelValid = true;
			 }//in wheel mode
			 else
			 {
				 MessageBox::Show("Please select jog mode or wheel mode" , "Mode Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;
			 }//neither jog nor wheel
		 }//button x plus click
private: System::Void button_xMinus_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 if (mmiDataPtr->opMode == JOG_MODE)
			 {
				 if (cncDataPtr->mmiData.jogCartesian == true)
				 {
					 if( mmiDataPtr->jogDirection[0] == -1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[0] = 0;
						 button_xMinus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if (mmiDataPtr->jogDirection[0] == 1 ||						  
							 mmiDataPtr->jogDirection[1] == 1 ||mmiDataPtr->jogDirection[1]==-1||
							 mmiDataPtr->jogDirection[2] == 1 ||mmiDataPtr->jogDirection[2]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[0] = -1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G01 G91 X-300 Y0 Z0\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_xMinus->BackColor = Color::SteelBlue;						 
					 }
				 }//if Cartesian x- true
				 else
				 {
					 if( mmiDataPtr->jogDirection[0] == -1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[0] = 0;
						 button_xMinus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if (mmiDataPtr->jogDirection[0] == 1 ||
							 mmiDataPtr->jogDirection[1] == 1 ||mmiDataPtr->jogDirection[1]==-1||
							 mmiDataPtr->jogDirection[2] == 1 ||mmiDataPtr->jogDirection[2]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[0] = -1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G00 G91 U-30000 V0 W0\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_xMinus->BackColor = Color::SteelBlue;
					 }
				 }//if Cartesian x- false
			 }//if jog mode is true
			 else if (cncDataPtr->mmiData.opMode == WHEEL_MODE)
			 {
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 FILE* wheelPtr;
				 wheelPtr = fopen("../TempNcCode/ncfile.txt","w");
				 fprintf(wheelPtr,"N100 G01 G91 X-%f Y0 Z0 \nM30",mmiDataPtr->wheelMultiple);
				 fclose(wheelPtr);
				 mmiDataPtr->wheelValid = true;
			 }//in wheel mode
			 else
			 {
				 MessageBox::Show("Please select jog mode or wheel mode" , "Mode Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;
			 }//neither jog nor wheel

		 }//button x minus click
private: System::Void button_yPlus_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (mmiDataPtr->opMode == JOG_MODE)
			 {
				 if (cncDataPtr->mmiData.jogCartesian == true)
				 {
					 if( mmiDataPtr->jogDirection[1] == 1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[1] = 0;
						 button_yPlus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if ( mmiDataPtr->jogDirection[1] == -1 ||						  
				 			  mmiDataPtr->jogDirection[0] == 1 ||mmiDataPtr->jogDirection[0]==-1||
				   			  mmiDataPtr->jogDirection[2] == 1 ||mmiDataPtr->jogDirection[2]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[1] = 1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G01 G91 X0 Y300 Z0\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_yPlus->BackColor = Color::SteelBlue;
					 }
				 }//if in Cartesian coordinates y+
				 else
				 {
					 if( mmiDataPtr->jogDirection[1] == 1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[1] = 0;
						 button_yPlus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if ( mmiDataPtr->jogDirection[1] == -1||						  
							  mmiDataPtr->jogDirection[0] == 1 ||mmiDataPtr->jogDirection[0]==-1||
							  mmiDataPtr->jogDirection[2] == 1 ||mmiDataPtr->jogDirection[2]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[1] = 1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G00 G91 U0 V30000 W0\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_yPlus->BackColor = Color::SteelBlue;						 
					 }
				 }//if in uvw v+
			 }//if in jog mode
			 else if (cncDataPtr->mmiData.opMode == WHEEL_MODE)
			 {
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 FILE* wheelPtr;
				 wheelPtr = fopen("../TempNcCode/ncfile.txt","w");
				 fprintf(wheelPtr,"N100 G01 G91 X0 Y%f Z0 \nM30",mmiDataPtr->wheelMultiple);
				 fclose(wheelPtr);
				 mmiDataPtr->wheelValid = true;
			 }//in wheel mode
			 else
			 {
				 MessageBox::Show("Please select jog mode or wheel mode" , "Mode Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;
			 }//neither jog nor wheel
		 }//button y+ click
private: System::Void button_yMinus_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (mmiDataPtr->opMode == JOG_MODE)
			 {
				 if (cncDataPtr->mmiData.jogCartesian == true)
				 {
					 if( mmiDataPtr->jogDirection[1] == -1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[1] = 0;
						 button_yMinus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if (mmiDataPtr->jogDirection[1] == 1 ||						  
							 mmiDataPtr->jogDirection[0] == 1 ||mmiDataPtr->jogDirection[0]==-1||
							 mmiDataPtr->jogDirection[2] == 1 ||mmiDataPtr->jogDirection[2]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[1] = -1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G01 G91 X0 Y-300 Z0\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_yMinus->BackColor = Color::SteelBlue;
					 }
				 }//if Cartesian y- true
				 else
				 {
					 if( mmiDataPtr->jogDirection[1] == -1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[1] = 0;
						 button_yMinus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if (mmiDataPtr->jogDirection[1] == 1 ||						  
							 mmiDataPtr->jogDirection[0] == 1 ||mmiDataPtr->jogDirection[0]==-1||
							 mmiDataPtr->jogDirection[2] == 1 ||mmiDataPtr->jogDirection[2]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[1] = -1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G00 G91 U0 V-30000 W0\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_yMinus->BackColor = Color::SteelBlue;
					 }
				 }//if Cartesian y- false
			 }//if jog mode is true
			 else if (cncDataPtr->mmiData.opMode == WHEEL_MODE)
			 {
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 FILE* wheelPtr;
				 wheelPtr = fopen("../TempNcCode/ncfile.txt","w");
				 fprintf(wheelPtr,"N100 G01 G91 X0 Y-%f Z0 \nM30",mmiDataPtr->wheelMultiple);
				 fclose(wheelPtr);
				 mmiDataPtr->wheelValid = true;
			 }//in wheel mode
			 else
			 {
				 MessageBox::Show("Please select jog mode or wheel mode" , "Mode Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;
			 }//neither jog nor wheel
		 }//y-click
private: System::Void button_zPlus_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (mmiDataPtr->opMode == JOG_MODE)
			 {
				 if (cncDataPtr->mmiData.jogCartesian == true)
				 {
					 if( mmiDataPtr->jogDirection[2] == 1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[2] = 0;
						 button_zPlus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if ( mmiDataPtr->jogDirection[2] == -1 ||						  
							 mmiDataPtr->jogDirection[0] == 1 ||mmiDataPtr->jogDirection[0]==-1||
							 mmiDataPtr->jogDirection[1] == 1 ||mmiDataPtr->jogDirection[1]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[2] = 1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G01 G91 X0 Y0 Z300\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_zPlus->BackColor = Color::SteelBlue;
					 }
				 }//if in Cartesian coordinates z+
				 else
				 {
					 if( mmiDataPtr->jogDirection[2] == 1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[2] = 0;
						 button_zPlus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if ( mmiDataPtr->jogDirection[2] == -1||						  
							 mmiDataPtr->jogDirection[0] == 1 ||mmiDataPtr->jogDirection[0]==-1||
							 mmiDataPtr->jogDirection[1] == 1 ||mmiDataPtr->jogDirection[1]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[2] = 1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G00 G91 U0 V0 W300\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_zPlus->BackColor = Color::SteelBlue;
					 }
				 }//if in uvw z+
			 }//if in jog mode
			 else if (cncDataPtr->mmiData.opMode == WHEEL_MODE)
			 {
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 FILE* wheelPtr;
				 wheelPtr = fopen("../TempNcCode/ncfile.txt","w");
				 fprintf(wheelPtr,"N100 G01 G91 X0 Y0 Z%f \nM30",mmiDataPtr->wheelMultiple);
				 fclose(wheelPtr);
				 mmiDataPtr->wheelValid = true;
			 }//in wheel mode
			 else
			 {
				 MessageBox::Show("Please select jog mode or wheel mode" , "Mode Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;
			 }//neither jog nor wheel
		 }//zplus click
private: System::Void button_zMinus_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (mmiDataPtr->opMode == JOG_MODE)
			 {
				 if (cncDataPtr->mmiData.jogCartesian == true)
				 {
					 if( mmiDataPtr->jogDirection[2] == -1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[2] = 0;
						 button_zMinus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if (mmiDataPtr->jogDirection[2] == 1 ||						  
							 mmiDataPtr->jogDirection[0] == 1 ||mmiDataPtr->jogDirection[0]==-1||
							 mmiDataPtr->jogDirection[1] == 1 ||mmiDataPtr->jogDirection[1]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[2] = -1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G01 G91 X0 Y0 Z-300\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_zMinus->BackColor = Color::SteelBlue;
					 }
				 }//if Cartesian z- true
				 else
				 {
					 if( mmiDataPtr->jogDirection[2] == -1)
					 {
						 decReset(decDataPtr);
						 intpReset(intpDataPtr);
						 mmiDataPtr->jogDirection[2] = 0;
						 button_zMinus->BackColor = Color::LightCyan;
						 cncDataPtr->mmiData.jogValid = false;
					 }
					 else
					 {
						 if (mmiDataPtr->jogDirection[2] == 1 ||						  
							 mmiDataPtr->jogDirection[0] == 1 ||mmiDataPtr->jogDirection[0]==-1||
							 mmiDataPtr->jogDirection[1] == 1 ||mmiDataPtr->jogDirection[1]==-1)
						 {
							 decReset(decDataPtr);
							 intpReset(intpDataPtr);
						 }
						 for (int i = 0 ; i < 3 ; i ++)
						 {
							 mmiDataPtr->jogDirection[i] = 0;
						 }
						 mmiDataPtr->jogDirection[2] = -1;
						 FILE* jogPtr;
						 jogPtr = fopen("../TempNcCode/ncfile.txt","w");
						 fprintf(jogPtr,"N100 G00 G91 U0 V0 W-300\nM30");
						 fclose(jogPtr);
						 cncDataPtr->mmiData.jogValid = true;
						 jogDisplayReset();
						 button_zMinus->BackColor = Color::SteelBlue;
					 }
				 }//if Cartesian z- false
			 }//if jog mode is true
			 else if (cncDataPtr->mmiData.opMode == WHEEL_MODE)
			 {
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 FILE* wheelPtr;
				 wheelPtr = fopen("../TempNcCode/ncfile.txt","w");
				 fprintf(wheelPtr,"N100 G01 G91 X0 Y0 Z-%f \nM30",mmiDataPtr->wheelMultiple);
				 fclose(wheelPtr);
				 mmiDataPtr->wheelValid = true;
			 }//in wheel mode
			 else
			 {
				 MessageBox::Show("Please select jog mode or wheel mode" , "Mode Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;
			 }//neither jog nor wheel
		 }//z-click
private: System::Void button_speedx1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (cncDataPtr->mmiData.opMode == WHEEL_MODE)
			 {
				 mmiDataPtr->wheelMultiple = 0.001;
				 button_speedx1->BackColor = System::Drawing::Color::SteelBlue;
				 button_speedx10->BackColor = System::Drawing::Color::AliceBlue;
				 button_speedx100->BackColor = System::Drawing::Color::AliceBlue;
			 } 
			 else
			 {
				 MessageBox::Show("Please select wheel mode" , "Mode Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;
			 }
		 }
private: System::Void button_speedx10_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (cncDataPtr->mmiData.opMode == WHEEL_MODE)
			 {
				 mmiDataPtr->wheelMultiple = 0.01;
				 button_speedx1->BackColor = System::Drawing::Color::AliceBlue;
				 button_speedx10->BackColor = System::Drawing::Color::SteelBlue;
				 button_speedx100->BackColor = System::Drawing::Color::AliceBlue;
			 } 
			 else
			 {
				 MessageBox::Show("Please select wheel mode" , "Mode Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;
			 }
		 }
private: System::Void button_speedx100_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (cncDataPtr->mmiData.opMode == WHEEL_MODE)
			 {
				 mmiDataPtr->wheelMultiple = 0.1;
				 button_speedx1->BackColor = System::Drawing::Color::AliceBlue;
				 button_speedx10->BackColor = System::Drawing::Color::AliceBlue;
				 button_speedx100->BackColor = System::Drawing::Color::SteelBlue;
			 } 
			 else
			 {
				 MessageBox::Show("Please select wheel mode" , "Mode Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;
			 }
		 }
private: System::Void button_save_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 double a = intpDataPtr->axisData[0].rActValue;
			 double b = intpDataPtr->axisData[1].rActValue;
			 double c = intpDataPtr->axisData[2].rActValue; 
			 FILE* teachPtr;
			 teachPtr = fopen("../TempNcCode/teachFile.txt","a+");
			 fprintf(teachPtr,"N100 G01 G90 X%f Y%f Z%f\n ",a,b,c);
			 fclose(teachPtr);
		 }
private: System::Void button_clr_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 FILE* teachPtr;
			 teachPtr = fopen("../TempNcCode/teachFile.txt","w");
			 fprintf(teachPtr,"");
			 fclose(teachPtr);
		 }
private: System::Void button_fh_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (mmiDataPtr->feedHold == true)
			 {
				 mmiDataPtr->feedHold = false;
				 button_fh->BackColor = System::Drawing::Color::SteelBlue;
			 }
			 else
			 {
				 mmiDataPtr->feedHold = true;
				 button_fh->BackColor = System::Drawing::Color::AliceBlue;
			 }
		 }
private: System::Void button_m01_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 intpDataPtr->mzero = true;
			 mmiDataPtr->mOne   = true;
		 }
private: System::Void trackBar_feedOverride_Scroll(System::Object^  sender, System::EventArgs^  e)
		 {
			 mmiDataPtr->feedModify = true;
			 mmiDataPtr->feedOverride = trackBar_feedOverride->Value;
		     label_feedOverride->Text = trackBar_feedOverride->Value.ToString()+"%";
		 }
private: System::Void EmergencyStop_Click(System::Object^  sender, System::EventArgs^  e) 
		 { 
			 if( EmergencyStop->BackColor == System::Drawing::Color::Red )
			 {
				 intpDataPtr->slopeDataPtr->instSpeed = 0;
				 decReset(decDataPtr);
				 intpReset(intpDataPtr);
				 EmergencyStop->Text = L"Continue";
				 EmergencyStop->BackColor = System::Drawing::Color::Purple;
			 }
			 else
			 {
				 EmergencyStop->Text = L"Emergency Stop";
				 EmergencyStop->BackColor = System::Drawing::Color::Red;
			 }
		 }
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
		 {
			 // close motion card and card timer
#if HD_TIMER
			 disableHDTimer();
			 closeMotionCard();
#endif
		 }
private: System::Void button_reset_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 decReset(decDataPtr);
			 intpReset(intpDataPtr);
			 memDisplayReset();
			 jogDisplayReset();
			 mmiDataPtr->mOne = false;
			 mmiDataPtr->decError = false;
		 }
//**************************************************************************************************
//  DISPLAY
//**************************************************************************************************
void display (void)
{
	u_valueDisplay ->Text = intpDataPtr->axisData[0].mActValue.ToString("0.00");
	v_valueDisplay ->Text = intpDataPtr->axisData[1].mActValue.ToString("0.00");
	w_valueDisplay ->Text = intpDataPtr->axisData[2].mActValue.ToString("0.00");

	x_valueDisplay ->Text = intpDataPtr->axisData[0].rActValue.ToString("0.00");
	y_valueDisplay ->Text = intpDataPtr->axisData[1].rActValue.ToString("0.00");
	z_valueDisplay ->Text = intpDataPtr->axisData[2].rActValue.ToString("0.00");
	if (intpDataPtr->mThirty == true)
	{
	label_M30->BackColor = Color::Gold; 
	}
	else
	{
	label_M30->BackColor = Color::GhostWhite;
	}
	if(mmiDataPtr->decError == true)
	{
		label_ERR->BackColor = Color::Red;
		mmiDataPtr->decError = false;
		MessageBox::Show(mmiDataPtr->decErrorState.ToString(),"Decoder Error" , MessageBoxButtons::OK , MessageBoxIcon::Warning ) ;		
	}
	else
	{
		label_ERR->BackColor = Color::GhostWhite;
	}
	if (intpDataPtr->intpState == INTP_ERROR)
	{
		label_ERR->BackColor = Color::Violet;
	}
	else
	{
		label_ERR->BackColor = Color::GhostWhite;
	}
	if (intpDataPtr->mzero == true)
	{
		label_M00->BackColor = Color::DarkCyan;
	}
	else
	{
		label_M00->BackColor = Color::GhostWhite;
	}
	if (mmiDataPtr->mOne == true)
	{
		label_M01->BackColor = Color::DarkCyan;
	}
	else
	{
		label_M01->BackColor = Color::GhostWhite;
	}
	if ((intpDataPtr->axisData[0].rActValue <= 0.001)&&(intpDataPtr->axisData[0].rActValue >= -0.001))
	{
		label_INY->BackColor = Color::Violet;
	}
	else
	{
		label_INY->BackColor = Color::GhostWhite;
	}
	if ((intpDataPtr->axisData[1].rActValue <= 0.001)&&(intpDataPtr->axisData[1].rActValue >= -0.001))
	{
		label_INX->BackColor = Color::Violet;
	}
	else
	{
		label_INX->BackColor = Color::GhostWhite;
	}
	if ((intpDataPtr->axisData[0].rActValue <= 0.001)&&(intpDataPtr->axisData[0].rActValue >= -0.001)&&
		(intpDataPtr->axisData[1].rActValue <= 0.001)&&(intpDataPtr->axisData[1].rActValue >= -0.001))
	{
		label_INZ->BackColor = Color::Violet;
	}
	else
	{
		label_INZ->BackColor = Color::GhostWhite;
	}
	if ((intpDataPtr->axisData[0].rActValue <= 75.001)&&(intpDataPtr->axisData[0].rActValue>=74.999))
	{
		label_HX->BackColor = Color::Violet;
	} 
	else
	{
		label_HX->BackColor = Color::GhostWhite;
	}
	if ((intpDataPtr->axisData[1].rActValue <= 75.001)&&(intpDataPtr->axisData[1].rActValue>=74.999))
	{
		label_HY->BackColor = Color::Violet;
	} 
	else
	{
		label_HY->BackColor = Color::GhostWhite;
	}
	if ((intpDataPtr->axisData[2].rActValue <= 0.001)&&(intpDataPtr->axisData[2].rActValue>=-0.001))
	{
		label_HZ->BackColor = Color::Violet;
	} 
	else
	{
		label_HZ->BackColor = Color::GhostWhite;
	}
}//display for form labels
//**************************************************************************************************
// DISPLAY RESETS
//**************************************************************************************************
void memDisplayReset(void)
{
	richTextBox_fileContent	->Text = "";
	richTextBox_fileName	->Text = "";
	return;
} //memDisplayReset()
void jogDisplayReset(void)
{
	button_xPlus->BackColor = Color::LightCyan;
	button_xMinus->BackColor = Color::LightCyan;
	button_yPlus->BackColor = Color::LightCyan;
	button_yMinus->BackColor = Color::LightCyan;
	button_zPlus->BackColor = Color::LightCyan;
	button_zMinus->BackColor = Color::LightCyan;
}
void modeDisplayReset(void)
{
	button_memory->BackColor = System::Drawing::SystemColors::MenuHighlight;
	button_MDI->BackColor = System::Drawing::SystemColors::MenuHighlight;
	button_jog->BackColor = System::Drawing::SystemColors::MenuHighlight;
	button_wheel->BackColor = System::Drawing::SystemColors::MenuHighlight;
	button_home->BackColor = System::Drawing::SystemColors::MenuHighlight;
}
void wheelDisplayReset(void)
{
	button_speedx1->BackColor = System::Drawing::Color::AliceBlue;	
	button_speedx10->BackColor = System::Drawing::Color::AliceBlue;
	button_speedx100->BackColor = System::Drawing::Color::AliceBlue;
}




};//	public ref class Form1 : public System::Windows::Forms::Form
}//namespace iCNC

