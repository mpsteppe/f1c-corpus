char *__thiscall sub_4056A0(char *this, int a2)
{
  int v2; // eax
  char v4; // cl
  int v5; // edx
  int v6; // edx
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  int v20; // [esp+4h] [ebp-20h] BYREF
  int v21; // [esp+8h] [ebp-1Ch] BYREF
  int v22; // [esp+Ch] [ebp-18h] BYREF
  int v23; // [esp+10h] [ebp-14h] BYREF
  int v24; // [esp+14h] [ebp-10h] BYREF
  int v25; // [esp+18h] [ebp-Ch] BYREF
  int v26; // [esp+1Ch] [ebp-8h] BYREF
  int v27; // [esp+20h] [ebp-4h] BYREF

  v2 = a2;
  v4 = *(_BYTE *)(a2 + 27);
  if ( (v4 & 0x20) != 0 && (v4 & 4) != 0 )
    v5 = *(_DWORD *)(a2 + 32);
  else
    v5 = *(_DWORD *)(a2 + 4);
  a2 = v5;
  v20 = v5 + 36;
  v6 = *(unsigned __int16 *)(v2 + 24);
  LOWORD(v2) = *(unsigned __int8 *)(v2 + 26);
  v21 = 16;
  v22 = 1;
  v27 = v2;
  v23 = ((v4 & 1) != 0) + 1;
  v26 = ((unsigned __int16)v23 * (unsigned __int16)v2) >> 3;
  v24 = v6;
  v25 = v6 * (unsigned __int16)v26;
  v7 = sub_405670(this + 68, aRiff, 4u);
  v8 = sub_405670(v7, &v20, 4u);
  v9 = sub_405670(v8, aWave, 4u);
  v10 = sub_405670(v9, aFmt, 4u);
  v11 = sub_405670(v10, &v21, 4u);
  v12 = sub_405670(v11, &v22, 2u);
  v13 = sub_405670(v12, &v23, 2u);
  v14 = sub_405670(v13, &v24, 4u);
  v15 = sub_405670(v14, &v25, 4u);
  v16 = sub_405670(v15, &v26, 2u);
  v17 = sub_405670(v16, &v27, 2u);
  v18 = sub_405670(v17, aData_0, 4u);
  return sub_405670(v18, &a2, 4u);
}

