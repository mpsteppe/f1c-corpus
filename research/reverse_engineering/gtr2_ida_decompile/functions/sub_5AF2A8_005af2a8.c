float *__stdcall sub_5AF2A8(float *a1, float *a2)
{
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]
  unsigned int v10; // [esp+8h] [ebp-4h]
  unsigned int v11; // [esp+8h] [ebp-4h]

  _EDX = a2;
  __asm
  {
    fld     dword ptr [edx]
    fmul    dword ptr [edx]
    fld     dword ptr [edx+4]
    fmul    dword ptr [edx+4]
    fld     dword ptr [edx+8]
    fmul    dword ptr [edx+8]
    fxch    st(2)
    faddp   st(1), st
    faddp   st(1), st
    fst     [ebp+var_8]
  }
  if ( v8 == 0.0 )
  {
    __asm { ffree   st }
    *(_DWORD *)a1 = LOBYTE(v8);
    *((_DWORD *)a1 + 1) = LOBYTE(v8);
    *((_DWORD *)a1 + 2) = LOBYTE(v8);
  }
  else
  {
    __asm
    {
      fld1
      fsubp   st(1), st
      fstp    [ebp+var_4]
    }
    if ( (LODWORD(v9) & 0x7FFFFFFFu) > 0x3727C5AC )
    {
      _EDI = (LODWORD(v8) >> 12) & 0xFF8;
      v10 = (unsigned int)byte_FFFFFF & LODWORD(v8) | 0x3F000000;
      __asm
      {
        fld     [ebp+var_4]
        fmul    dword ptr [edi+904D50h]
      }
      __asm { fadd    dword ptr [edi+904D54h] }
      v11 = ((unsigned int)(-1090519041 - LODWORD(v8)) >> 1) & 0xFF800000;
      __asm
      {
        fmul    [ebp+var_4]
        fld     dword ptr [edx]
        fmul    st, st(1)
        fld     dword ptr [edx+4]
        fmul    st, st(2)
        fld     dword ptr [edx+8]
        fmul    st, st(3)
        fxch    st(2)
        fstp    dword ptr [ecx]
      }
      *a1 = _ET1;
      __asm { fstp    dword ptr [ecx+4] }
      a1[1] = _ET1;
      __asm { fstp    dword ptr [ecx+8] }
      a1[2] = _ET1;
      __asm { fstp    st }
    }
    else if ( a1 != a2 )
    {
      *a1 = *a2;
      a1[1] = a2[1];
      a1[2] = a2[2];
    }
  }
  return a1;
}
