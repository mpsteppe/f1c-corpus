int __thiscall sub_5DF580(_DWORD *this, char *EndPtr, int *a3, int *a4, int *a5, int *a6)
{
  int v7; // esi
  int v8; // eax
  int *v9; // edi
  char *v10; // eax
  int *v11; // edi
  int *v12; // edi
  int v13; // eax
  char *v14; // edx
  int *v15; // edi

  v7 = 0;
  if ( sub_5DEF70() )
  {
    v8 = this[515];
    v9 = a3;
    v10 = (char *)(v8 + 1);
    v7 = 1;
    EndPtr = v10;
    if ( a3 )
    {
      v7 = 2;
      *v9 = strtol(v10, &EndPtr, 10);
      v10 = EndPtr + 1;
    }
    v11 = a4;
    if ( a4 )
    {
      ++v7;
      *v11 = strtol(v10, &EndPtr, 10);
      v10 = EndPtr + 1;
    }
    v12 = a5;
    if ( a5 )
    {
      ++v7;
      v13 = strtol(v10, &EndPtr, 10);
      v14 = EndPtr;
      *v12 = v13;
      v10 = v14 + 1;
    }
    v15 = a6;
    if ( a6 )
    {
      ++v7;
      *v15 = strtol(v10, &EndPtr, 10);
    }
  }
  return v7;
}
