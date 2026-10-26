// Function: FUN_004d36d0 @ 004d36d0
// Strings:  [D:\dev\F1_1999_2002\Source\steward.cpp, PITSTOP, TIMING, VEHICLE, Entered Steward::Setup()]


void FUN_004d36d0(void)

{
  char cVar1;
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0x91a);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_Steward__Setup___005d41ec);
  }
  FUN_005599d0(s_VEHICLE_005d41e4,0,0);
  FUN_00559a00(s_TIMING_005d41dc,&LAB_004d3740,0);
  FUN_00559a00(s_PITSTOP_005d41d4,&LAB_004d37b0,0);
  return;
}


