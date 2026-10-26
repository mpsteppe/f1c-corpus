int __thiscall sub_47C360(_DWORD *this, int a2)
{
  int v3; // esi
  LPVOID **v4; // edi
  char v5; // al
  int v6; // ebx
  int result; // eax
  char *v8; // eax
  const char *v9; // edi
  char *v10; // eax
  char *v11; // eax
  const char *v12; // edi
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // eax
  const char **v17; // esi
  int v18; // eax
  const char *v19; // eax
  char *v20; // esi
  unsigned int v21; // edx
  int v22; // eax
  char v23; // cl
  int v24; // [esp+14h] [ebp-158h]
  char v25; // [esp+18h] [ebp-154h] BYREF
  int v26; // [esp+19h] [ebp-153h]
  __int16 v27; // [esp+1Dh] [ebp-14Fh]
  char v28; // [esp+1Fh] [ebp-14Dh]
  char v29; // [esp+20h] [ebp-14Ch] BYREF
  int v30; // [esp+21h] [ebp-14Bh]
  __int16 v31; // [esp+25h] [ebp-147h]
  char v32; // [esp+27h] [ebp-145h]
  int v33; // [esp+28h] [ebp-144h]
  char v34[29]; // [esp+2Ch] [ebp-140h] BYREF
  __int16 v35; // [esp+49h] [ebp-123h]
  char v36; // [esp+4Bh] [ebp-121h]
  _BYTE v37[29]; // [esp+4Ch] [ebp-120h] BYREF
  __int16 v38; // [esp+69h] [ebp-103h]
  char v39; // [esp+6Bh] [ebp-101h]
  char v40[253]; // [esp+6Ch] [ebp-100h] BYREF
  __int16 v41; // [esp+169h] [ebp-3h]
  char v42; // [esp+16Bh] [ebp-1h]

  v3 = this[17];
  while ( v3 )
  {
    v4 = (LPVOID **)v3;
    v5 = *(_BYTE *)(v3 + 8);
    v3 = *(_DWORD *)(v3 + 4);
    if ( v5 && *v4 )
      sub_404F70(*v4, 1);
    sub_587BCF(v4);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  v40[0] = byte_5EA438[0];
  memset(&v40[1], 0, 0xFCu);
  v41 = 0;
  v42 = 0;
  sub_489CB0(this);
  this[93] = a2;
  v6 = sub_4C2850(&unk_7D2DB0);
  if ( a2 )
  {
    result = a2 - 1;
    if ( a2 == 1 )
    {
      v8 = (char *)this[42];
      if ( !v8 )
        v8 = byte_5EA438;
      v9 = v8;
      result = 0;
      if ( strlen(v9) )
      {
        v10 = (char *)this[42];
LABEL_16:
        if ( !v10 )
          v10 = byte_5EA438;
        result = sub_566650(v10);
      }
    }
  }
  else
  {
    v11 = (char *)this[40];
    if ( !v11 )
      v11 = byte_5EA438;
    v12 = v11;
    result = 0;
    if ( strlen(v12) )
    {
      v10 = (char *)this[40];
      goto LABEL_16;
    }
  }
  if ( v6 )
  {
    v13 = sub_4C1370(v6);
    v37[0] = byte_5EA438[0];
    memset(&v37[1], 0, 0x1Cu);
    v38 = 0;
    v14 = v13 + 1;
    v33 = v13 + 1;
    v39 = 0;
    sub_4C1390(v6);
    sub_4C0A20(v37, 32);
    v15 = 0;
    v24 = 0;
    if ( v14 > 0 )
    {
      while ( 1 )
      {
        if ( v15 )
          v16 = sub_4C13A0(v15 - 1);
        else
          v16 = sub_4C1390(v6);
        v17 = (const char **)v16;
        v34[0] = byte_5EA438[0];
        memset(&v34[1], 0, 0x1Cu);
        v35 = 0;
        v36 = 0;
        v26 = 0;
        v30 = 0;
        v27 = 0;
        v31 = 0;
        v28 = 0;
        v25 = byte_5EA438[0];
        v29 = byte_5EA438[0];
        v32 = 0;
        v40[0] = 0;
        sub_58815F(&v25, "%d", *(_DWORD *)(v16 + 408));
        sub_4C0A20(v34, 32);
        v18 = sub_4C13C0(v34);
        sub_58815F(&v29, "%d", v18);
        if ( a2 )
        {
          if ( a2 != 1 )
            goto LABEL_35;
          v19 = *v17;
          if ( !*v17 )
            v19 = byte_5EA438;
          sub_58815F(v40, "%s", v19);
          sub_4894D0(v40);
          strcat(v40, v34);
          sub_4894D0(v40);
          v20 = &v25;
          v21 = strlen(&v25) + 1;
        }
        else
        {
          v22 = 0;
          do
          {
            v23 = v34[v22];
            v40[v22++] = v23;
          }
          while ( v23 );
          sub_4894D0(v40);
          v20 = &v29;
          v21 = strlen(&v29) + 1;
        }
        qmemcpy(&v40[strlen(v40)], v20, v21);
LABEL_35:
        if ( !(unsigned __int8)sub_489A50(v40, 0) )
          sub_489600(v40, 0, 0, 0, 0);
        if ( ++v24 >= v33 )
          break;
        v15 = v24;
      }
    }
    sub_489C10(0, aFtim14redoutli);
    if ( a2 )
    {
      if ( a2 == 1 )
        sub_48A3C0(1, 2);
    }
    else
    {
      sub_48A3C0(1, 1);
    }
    v40[0] = 0;
    return sub_489C10(0, aFtim14blkoutli);
  }
  return result;
}
