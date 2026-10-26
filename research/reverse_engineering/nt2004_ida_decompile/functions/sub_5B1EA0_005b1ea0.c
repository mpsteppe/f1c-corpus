int __thiscall sub_5B1EA0(int this, char *EndPtr, int *a3, int *a4, int *a5, int *a6)
{
  int v7; // edi
  int v8; // eax
  int *v9; // esi
  char *v10; // eax
  int v11; // eax
  char *v12; // edx
  int *v13; // esi
  int v14; // eax
  char *v15; // edx
  int *v16; // esi
  int v17; // eax
  char *v18; // edx
  int *v19; // esi

  v7 = 0;
  if ( sub_5B1D20((const char **)this, EndPtr) )
  {
    v8 = *(_DWORD *)(this + 2060);
    v9 = a3;
    v10 = (char *)(v8 + 1);
    v7 = 1;
    EndPtr = v10;
    if ( a3 )
    {
      v11 = strtol(v10, &EndPtr, 10);
      v12 = EndPtr;
      *v9 = v11;
      v10 = v12 + 1;
    }
    v13 = a4;
    if ( a4 )
    {
      v14 = strtol(v10, &EndPtr, 10);
      v15 = EndPtr;
      *v13 = v14;
      v10 = v15 + 1;
    }
    v16 = a5;
    if ( a5 )
    {
      v17 = strtol(v10, &EndPtr, 10);
      v18 = EndPtr;
      *v16 = v17;
      v10 = v18 + 1;
    }
    v19 = a6;
    if ( a6 )
      *v19 = strtol(v10, &EndPtr, 10);
  }
  return v7;
}
