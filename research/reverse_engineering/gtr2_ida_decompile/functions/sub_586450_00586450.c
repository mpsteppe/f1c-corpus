int __thiscall sub_586450(void *this, int a2)
{
  int v4; // eax
  int v5; // ebx
  int v6; // edi
  int v7; // ebx
  int v8; // edi
  int v9; // ebp
  int v10; // [esp+8h] [ebp-504h]
  char String2[28]; // [esp+Ch] [ebp-500h] BYREF
  _BYTE v12[36]; // [esp+28h] [ebp-4E4h] BYREF
  char v13[92]; // [esp+4Ch] [ebp-4C0h] BYREF
  char Buffer[28]; // [esp+A8h] [ebp-464h] BYREF
  _BYTE v15[12]; // [esp+D0h] [ebp-43Ch] BYREF
  _BYTE v16[12]; // [esp+DCh] [ebp-430h] BYREF
  char v17[500]; // [esp+E8h] [ebp-424h] BYREF
  char v18[12]; // [esp+2DCh] [ebp-230h] BYREF
  int v19; // [esp+2E8h] [ebp-224h]
  char v20; // [esp+2ECh] [ebp-220h]
  int v21; // [esp+2F4h] [ebp-218h]
  int v22; // [esp+2F8h] [ebp-214h]
  int v23; // [esp+2FCh] [ebp-210h]
  char Str[512]; // [esp+300h] [ebp-20Ch] BYREF
  int v25; // [esp+508h] [ebp-4h]

  sub_613B30(v13);
  memset(Str, 0, sizeof(Str));
  v25 = 0;
  v19 = 0;
  v23 = 0;
  v21 = 0;
  v22 = 0;
  v20 = 1;
  if ( (unsigned __int8)sub_614460(a2, 1) )
  {
    if ( sub_613DE0(Str, 512) )
    {
      do
      {
        if ( !sub_612EB0(v17) && strstr(Str, "[PHYSICAL]") && sub_613DE0(Str, 512) )
        {
          do
          {
            v4 = sub_612EB0(v17);
            if ( v4 == 1 )
              break;
            if ( !v4 )
            {
              sub_6134B0("RadiusAdd", (int)this, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("RadiusMult", (int)this + 4, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("RadiusMax", (int)this + 8, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("Engine", (int)this + 12, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("AeroDiv", (int)this + 16, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("AeroMin", (int)this + 20, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("VertMult", (int)this + 24, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("FrontWingDetach", (int)this + 28, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("FrontWingRandom", (int)this + 32, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("FrontWingPos", (int)this + 36, (int)this + 40, (int)this + 44, 0, 0, 0, 0, 0);
              sub_6134B0(
                "FrontWingMassInertia",
                (int)this + 48,
                (int)this + 52,
                (int)this + 56,
                (int)this + 60,
                0,
                0,
                0,
                0);
              sub_6134B0("FrontWingCollParams", (int)this + 64, (int)this + 68, (int)this + 72, 0, 0, 0, 0, 0);
              sub_6134B0("RearWingDetach", (int)this + 76, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("RearWingRandom", (int)this + 80, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("RearWingPos", (int)this + 84, (int)this + 88, (int)this + 92, 0, 0, 0, 0, 0);
              sub_6134B0(
                "RearWingMassInertia",
                (int)this + 96,
                (int)this + 100,
                (int)this + 104,
                (int)this + 108,
                0,
                0,
                0,
                0);
              sub_6134B0("RearWingCollParams", (int)this + 112, (int)this + 116, (int)this + 120, 0, 0, 0, 0, 0);
              sub_6134B0("TireCutDull", (int)this + 124, (int)this + 128, 0, 0, 0, 0, 0, 0);
              sub_6134B0("TireCutSharp", (int)this + 132, (int)this + 136, 0, 0, 0, 0, 0, 0);
              sub_6134B0("WheelBend", (int)this + 140, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("WheelDetach", (int)this + 144, 0, 0, 0, 0, 0, 0, 0);
              sub_6134B0("WheelRandom", (int)this + 148, 0, 0, 0, 0, 0, 0, 0);
              v5 = 0;
              v6 = (int)this + 160;
              do
              {
                sprintf(Buffer, "Wheel%dMassInertia", v5);
                sub_6134B0(Buffer, v6 - 8, v6 - 4, v6, v6 + 4, 0, 0, 0, 0);
                sprintf(Buffer, "Wheel%dCollParams", v5);
                sub_6134B0(Buffer, v6 + 8, v6 + 12, v6 + 16, 0, 0, 0, 0, 0);
                ++v5;
                v6 += 28;
              }
              while ( v5 < 4 );
              v7 = 0;
              v8 = (int)this + 432;
              v9 = (int)this + 332;
              v10 = (int)this + 296;
              do
              {
                sprintf(String2, "Part%dDetach", v7);
                sub_6134B0(String2, v10 - 32, 0, 0, 0, 0, 0, 0, 0);
                sprintf(String2, "Part%dRandom", v7);
                sub_6134B0(String2, v10, 0, 0, 0, 0, 0, 0, 0);
                sprintf(String2, "Part%dPos", v7);
                sub_6134B0(String2, v9 - 4, v9, v9 + 4, 0, 0, 0, 0, 0);
                sprintf(String2, "Part%dMassInertia", v7);
                sub_6134B0(String2, v8 - 8, v8 - 4, v8, v8 + 4, 0, 0, 0, 0);
                sprintf(String2, "Part%dCollParams", v7);
                sub_6134B0(String2, v8 + 8, v8 + 12, v8 + 16, 0, 0, 0, 0, 0);
                ++v7;
                v9 += 12;
                v8 += 28;
                v10 += 4;
              }
              while ( v7 < 8 );
              sub_6137E0(v17);
              sub_6137E0(v16);
              sub_6137E0(v15);
              sub_6134B0("WallSkidThresh", (int)this + 744, 0, 0, 0, 0, 0, 0, 0);
            }
          }
          while ( sub_613DE0(v18, 512) );
        }
      }
      while ( sub_613DE0(v18, 512) );
    }
    sub_613C30(v12);
    *(_DWORD *)&Str[484] = -1;
    sub_614140(v12);
    return 0;
  }
  else
  {
    v25 = -1;
    sub_614140(v13);
    return -1;
  }
}
