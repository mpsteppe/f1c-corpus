int __thiscall sub_4F1B50(_DWORD *this, char a2)
{
  int result; // eax
  int v3; // edx

  result = 0;
  v3 = this[3247];
  if ( a2 )
  {
    if ( v3 )
    {
      this[3387] = 0;
      this[3388] = 0;
      this[3389] = 0;
    }
    else
    {
      dword_7C74F8 = 2;
    }
  }
  else if ( !v3 )
  {
    dword_7C74F8 = 0;
  }
  return result;
}
