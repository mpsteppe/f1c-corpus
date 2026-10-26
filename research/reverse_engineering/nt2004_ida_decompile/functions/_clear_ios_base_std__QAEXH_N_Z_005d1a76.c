void __thiscall std::ios_base::clear(std::ios_base *this, char a2, int a3)
{
  int v3; // eax
  int v4; // ecx
  char *v5; // esi
  size_t v6; // eax
  void **pExceptionObject; // [esp+4h] [ebp-38h] BYREF
  _DWORD v8[7]; // [esp+20h] [ebp-1Ch] BYREF

  v3 = a2 & 7;
  *((_DWORD *)this + 1) = v3;
  v4 = v3 & *((_DWORD *)this + 2);
  if ( v4 )
  {
    if ( (_BYTE)a3 )
      _CxxThrowException(0, 0);
    if ( (v4 & 4) != 0 )
    {
      v5 = "ios::badbit set";
    }
    else
    {
      v5 = "ios::failbit set";
      if ( (v4 & 2) == 0 )
        v5 = "ios::eofbit set";
    }
    LOBYTE(v8[0]) = HIBYTE(a3);
    std::string::_Tidy(v8, 0);
    v6 = strlen(v5);
    std::string::assign((int)v8, v5, v6);
    v8[6] = 0;
    sub_5D1B12(v8);
    pExceptionObject = &std::ios_base::failure::`vftable';
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI3_AVfailure_ios_base_std__);
  }
}
