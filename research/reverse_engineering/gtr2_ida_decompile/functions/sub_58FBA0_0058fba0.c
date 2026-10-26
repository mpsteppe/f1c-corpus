char __stdcall sub_58FBA0(const char *a1, float a2, char a3)
{
  char v3; // bl
  const char *v4; // eax
  int v6; // esi
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // edi
  int v14; // ebx
  int v15; // eax
  int v16; // [esp-18h] [ebp-18Ch]
  int v17; // [esp-14h] [ebp-188h]
  int v18; // [esp+4h] [ebp-170h] BYREF
  _BYTE v19[4]; // [esp+8h] [ebp-16Ch] BYREF
  float v20; // [esp+Ch] [ebp-168h] BYREF
  float v21; // [esp+10h] [ebp-164h] BYREF
  _BYTE v22[80]; // [esp+14h] [ebp-160h] BYREF
  char Buffer[260]; // [esp+64h] [ebp-110h] BYREF
  int v24; // [esp+170h] [ebp-4h]

  v3 = 0;
  v21 = 0.0;
  sub_617DB0(v22, v18);
  v24 = 0;
  if ( !sub_4DD9B0((int)&v21, (char)a1, 0, 1) )
    goto LABEL_6;
  memset(Buffer, 0, 256);
  v4 = *(const char **)dword_91CAB0;
  if ( !*(_DWORD *)dword_91CAB0 )
    v4 = WindowName;
  sprintf(Buffer, "%s%s", v4, a1);
  v21 = 0.0;
  if ( sub_4DD9B0((int)&v21, (char)Buffer, 0, 1) )
  {
    v24 = -1;
    nullsub_7(v22);
    return 0;
  }
  else
  {
LABEL_6:
    if ( LODWORD(v21) )
    {
      sub_45DE00();
      v6 = *(_DWORD *)(sub_4DDFE0() + 8);
      v7 = sub_4DDFE0();
      v8 = *(_DWORD *)(LODWORD(v21) + 8);
      v9 = *(_DWORD *)(LODWORD(v21) + 4);
      v17 = *(_DWORD *)(v7 + 4);
      v10 = sub_4DDFE0();
      sub_4DDC20(v21, 0, 0, v9, v8, v10, 0, 0, v17, v6, -1, -1, -1, -1);
      sub_4DDA20();
      v11 = *(_DWORD *)(sub_4DDFE0() + 8);
      v12 = sub_4DDFE0();
      v13 = *(_DWORD *)(LODWORD(v20) + 8);
      v14 = *(_DWORD *)(LODWORD(v20) + 4);
      v16 = *(_DWORD *)(v12 + 4);
      v15 = sub_4DDFE0();
      sub_4DDC20(v20, 0, 0, v14, v13, v15, 0, 0, v16, v11, -1, -1, -1, -1);
      sub_4DDA20();
      sub_617DF0(1);
      if ( sub_617F80(&v20) < a2 )
      {
        do
        {
          if ( a3 )
          {
            sub_4617B0(0.050000001);
            if ( (dword_B698E8 & 1) != 0 && dword_B6A2F4 > 0 )
              break;
          }
        }
        while ( sub_617F80(v19) < a2 );
      }
      sub_4DD9C0();
      nullsub_7(&unk_B6E2A0);
      sub_45DDE0();
      v3 = 1;
    }
    *(_DWORD *)&Buffer[252] = -1;
    nullsub_7(&v18);
    return v3;
  }
}
