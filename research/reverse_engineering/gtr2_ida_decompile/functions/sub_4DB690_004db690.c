int __thiscall sub_4DB690(_DWORD *this, const char *a2)
{
  int v3; // edi
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  int v7; // edx
  char *v8; // eax
  float v10; // [esp+8h] [ebp-B0h]
  int v11; // [esp+Ch] [ebp-ACh] BYREF
  int v12; // [esp+10h] [ebp-A8h] BYREF
  int v13; // [esp+14h] [ebp-A4h] BYREF
  int v14; // [esp+18h] [ebp-A0h] BYREF
  int v15; // [esp+1Ch] [ebp-9Ch] BYREF
  int v16; // [esp+20h] [ebp-98h] BYREF
  char Str[4]; // [esp+24h] [ebp-94h] BYREF
  char v18; // [esp+28h] [ebp-90h]
  _BYTE v19[127]; // [esp+29h] [ebp-8Fh] BYREF
  int v20; // [esp+B0h] [ebp-8h]

  v18 = 0;
  memset(v19, 0, sizeof(v19));
  v15 = 0;
  *(_DWORD *)Str = 0;
  v13 = 0;
  *(float *)&v12 = 0.0;
  v14 = 0;
  v16 = 0;
  if ( !a2 || !strlen(a2) || sub_4E3AF0(this[194] + 1380, a2) )
    return -1;
  *(_DWORD *)&v19[123] = operator new(0x7Cu);
  v20 = 0;
  if ( *(_DWORD *)&v19[123] )
    v3 = sub_4E4220(this[194]);
  else
    v3 = 0;
  v20 = -1;
  sub_4E28C0(a2);
  while ( sub_4DAC90(this) )
  {
    if ( strstr(byte_75AF70, "}") )
      break;
    if ( sub_6131C0("SOUND_CLICK", (int)Str) )
    {
      sub_4E28D0(Str);
      sub_4E03A0(Str);
    }
    else if ( sub_6131C0("SOUND_RELEASE", (int)Str) )
    {
      sub_4E28E0(Str);
      sub_4E03A0(Str);
    }
    else if ( sub_6131C0("SOUND_FOCUS", (int)Str) )
    {
      sub_4E28F0(Str);
      sub_4E03A0(Str);
    }
    else if ( sub_6131C0("SOUND_LOSTFOCUS", (int)Str) )
    {
      sub_4E2900(Str);
      sub_4E03A0(Str);
    }
    else if ( sub_6131C0("SOUND_DRAG", (int)Str) )
    {
      sub_4E2910(Str);
      sub_4E03A0(Str);
    }
    else if ( sub_6134B0("SIZE", (int)&v12, (int)&v11, 0, 0, 0, 0, 0, 0) )
    {
      sub_4E2960((unsigned __int64)*(float *)&v12, (unsigned __int64)*(float *)&v11);
    }
    else if ( sub_6134B0("SECONDARYOFFSET", (int)&v12, (int)&v11, (int)&v13, (int)&v15, 0, 0, 0, 0) )
    {
      sub_4E3F40(
        v3 + 108,
        (unsigned __int64)*(float *)&v12 >> 32,
        0,
        (unsigned __int64)*(float *)&v12,
        (unsigned __int64)*(float *)&v11);
      sub_4E3F40(v3 + 108, (unsigned __int64)v10 >> 32, 1, (unsigned __int64)v10, (unsigned __int64)*(float *)&v12);
    }
    else if ( sub_6133A0("OFFSET_PAIR", (int)&v14, (int)&v16, 0, 0) )
    {
      sub_4E3EE0(v3 + 108, v14, v16);
    }
    else if ( sub_6131C0("FONT", (int)Str) || sub_6131C0("FONT1", (int)Str) )
    {
      sub_4E0520(Str);
      v8 = strstr(Str, ".BMP");
      if ( v8 )
        *v8 = 0;
      sub_4E2920(Str);
    }
    else if ( sub_6131C0("FONT2", (int)Str) )
    {
      sub_4E0520(Str);
      v4 = strstr(Str, ".BMP");
      if ( v4 )
        *v4 = 0;
      sub_4E2930(Str);
    }
    else if ( sub_6131C0("FONT3", (int)Str) )
    {
      sub_4E0520(Str);
      v5 = strstr(Str, ".BMP");
      if ( v5 )
        *v5 = 0;
      sub_4E2940(Str);
    }
    else if ( sub_6131C0("FONT4", (int)Str) )
    {
      sub_4E0520(Str);
      v6 = strstr(Str, ".BMP");
      if ( v6 )
        *v6 = 0;
      sub_4E2950(Str);
    }
    else if ( sub_6137E0(&unk_75AD58) )
    {
      sub_4DB150(this, v7, v3, 0);
    }
  }
  return off_16C9480(a2);
}
