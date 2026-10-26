char *__stdcall sub_517899(char *a1, char *a2, char *a3)
{
  char *v3; // eax
  int v6; // edi
  float *v8; // ebx
  char *result; // eax
  char v11; // [esp+0h] [ebp-44h] BYREF
  char *v12; // [esp+40h] [ebp-4h]

  v3 = a1;
  if ( a1 == a2 || a1 == a3 )
    v3 = &v11;
  v12 = v3;
  _ECX = a2;
  _EDX = a3;
  v6 = -4;
  do
  {
    _ESI = -4;
    v8 = (float *)&v3[4 * v6 + 16];
    __asm
    {
      fld     dword ptr [ecx]
      fld     dword ptr [ecx+4]
      fld     dword ptr [ecx+8]
      fld     dword ptr [ecx+0Ch]
    }
    do
    {
      __asm
      {
        fld     st(3)
        fmul    dword ptr [edx+esi*4+10h]
        fld     st(3)
        fmul    dword ptr [edx+esi*4+20h]
        fld     st(3)
        fmul    dword ptr [edx+esi*4+30h]
        fld     st(3)
        fmul    dword ptr [edx+esi*4+40h]
        fxch    st(3)
        faddp   st(1), st
        fxch    st(2)
        faddp   st(1), st
        faddp   st(1), st
        fstp    dword ptr [ebx]
      }
      *v8 = _ET1;
      v8 += 4;
      ++_ESI;
    }
    while ( _ESI );
    __asm
    {
      ffree   st(3)
      ffree   st(2)
      ffree   st(1)
      ffree   st
    }
    _ECX += 16;
    ++v6;
  }
  while ( v6 );
  result = a1;
  if ( v12 != a1 )
    qmemcpy(a1, v12, 0x40u);
  return result;
}

