_BYTE *__stdcall sub_554744(_BYTE *a1, _BYTE *a2, _BYTE *a3)
{
  _BYTE *result; // eax
  _BYTE *v4; // ebx
  _BYTE *v10; // ebx
  int v13; // edi
  _BYTE v16[64]; // [esp+Ch] [ebp-40h] BYREF

  result = a1;
  if ( a3 == a1 )
  {
    if ( a2 != a1 )
    {
      v4 = a1;
      _ECX = a2;
      _EDX = a3;
      _EDI = -4;
      do
      {
        _ESI = -16;
        __asm
        {
          fld     dword ptr [edx+edi*4+10h]
          fld     dword ptr [edx+edi*4+20h]
          fld     dword ptr [edx+edi*4+30h]
          fld     dword ptr [edx+edi*4+40h]
        }
        do
        {
          __asm
          {
            fld     st(3)
            fmul    dword ptr [ecx+esi*4+40h]
            fld     st(3)
            fmul    dword ptr [ecx+esi*4+44h]
            fld     st(3)
            fmul    dword ptr [ecx+esi*4+48h]
            fld     st(3)
            fmul    dword ptr [ecx+esi*4+4Ch]
            fxch    st(3)
            faddp   st(1), st
            fxch    st(2)
            faddp   st(1), st
            faddp   st(1), st
            fstp    dword ptr [ebx+esi*4+40h]
          }
          *(float *)&v4[4 * _ESI + 64] = _ET1;
          _ESI += 4;
        }
        while ( _ESI );
        __asm
        {
          ffree   st(3)
          ffree   st(2)
          ffree   st(1)
          ffree   st
        }
        v4 += 4;
        ++_EDI;
      }
      while ( _EDI );
      return result;
    }
    qmemcpy(v16, a3, sizeof(v16));
    a3 = v16;
  }
  v10 = a1;
  _ECX = a2;
  _EDX = a3;
  v13 = -4;
  do
  {
    _ESI = -4;
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
        fstp    dword ptr [ebx+esi*4+10h]
      }
      *(float *)&v10[4 * _ESI++ + 16] = _ET1;
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
    v10 += 16;
    ++v13;
  }
  while ( v13 );
  return result;
}
