void __userpurge sub_540E96(int a1@<eax>, unsigned int a2, int a3, int a4, int a5, int a6, float a7)
{
  const char *v7; // eax
  _DWORD v8[5]; // [esp+1Ch] [ebp-118h] BYREF
  char v9; // [esp+30h] [ebp-104h]
  char Buffer[244]; // [esp+34h] [ebp-100h] BYREF
  int v11; // [esp+128h] [ebp-Ch]
  void *v12; // [esp+12Ch] [ebp-8h]
  int v13; // [esp+130h] [ebp-4h]

  v13 = -1;
  v12 = &SEH_540FD0;
  v11 = a1;
  if ( !dword_BE1D0C )
  {
LABEL_4:
    if ( !dword_BE1D18 )
      return;
    goto LABEL_5;
  }
  if ( !dword_BE1D18 )
  {
    dword_BE1D18 = (*(int (**)(void))(*(_DWORD *)dword_BE1D0C + 96))();
    goto LABEL_4;
  }
LABEL_5:
  if ( a2 < 8 )
  {
    sub_40B430();
    v7 = (const char *)dword_91CA88;
    if ( !dword_91CA88 )
      v7 = WindowName;
    sprintf(Buffer, "%s%s", v7, off_903918[a2]);
    sub_615860(Buffer);
    v8[3] = -1;
    v8[4] = -1;
    v9 = 0;
    if ( a2 == 5 || a2 == 6 || a2 == 7 )
      a7 = *(float *)&dword_B70948 * a7;
    (*(void (__thiscall **)(int, float))(*(_DWORD *)dword_BE1D18 + 28))(dword_BE1D18, COERCE_FLOAT(LODWORD(a7)));
    (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)dword_BE1D18 + 4))(dword_BE1D18, v8);
    j_j__free((void *)1);
  }
}
