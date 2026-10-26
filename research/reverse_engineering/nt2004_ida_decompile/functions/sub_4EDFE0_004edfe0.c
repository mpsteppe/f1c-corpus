int __thiscall sub_4EDFE0(int this, char a2)
{
  float **v3; // edi
  char v4; // bl
  int v5; // ecx
  int result; // eax
  _BYTE v7[12]; // [esp+Ch] [ebp-18h] BYREF
  _BYTE v8[12]; // [esp+18h] [ebp-Ch] BYREF

  v3 = (float **)(this + 20836);
  sub_4DC2C0((_DWORD *)(this + 20836));
  v4 = sub_4F8F90(this, v8, v7);
  if ( a2 || !sub_4DD970(v3, 0.0) )
  {
    sub_51BE20(v8, v7);
    sub_514EB0(this + 84);
    sub_51E820(0);
    v5 = this + 16588;
    if ( v4 )
    {
      sub_4C1960(v5);
      if ( (unsigned __int8)sub_4EED40(this) && dword_75CBB0 == 7 )
        *(_BYTE *)(this + 17412) = 1;
    }
    else
    {
      sub_4C1940(v5);
    }
  }
  result = sub_421180((_DWORD *)this);
  if ( dword_75CBB0 == 7 )
  {
    result = dword_75CBB4;
    if ( dword_75CBB4 == 3 || dword_75CBB4 == 4 )
      return sub_51C0E0(0);
  }
  return result;
}
