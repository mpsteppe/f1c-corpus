int __thiscall sub_5B1F50(int this, char *EndPtr, float *a3, float *a4, float *a5, float *a6)
{
  int v7; // edi
  int v8; // eax
  float *v9; // esi
  char *v10; // eax
  float *v11; // esi
  float *v12; // esi
  float *v13; // esi

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
      *v9 = strtod(v10, &EndPtr);
      v10 = EndPtr + 1;
    }
    v11 = a4;
    if ( a4 )
    {
      *v11 = strtod(v10, &EndPtr);
      v10 = EndPtr + 1;
    }
    v12 = a5;
    if ( a5 )
    {
      *v12 = strtod(v10, &EndPtr);
      v10 = EndPtr + 1;
    }
    v13 = a6;
    if ( a6 )
      *v13 = strtod(v10, &EndPtr);
  }
  return v7;
}
