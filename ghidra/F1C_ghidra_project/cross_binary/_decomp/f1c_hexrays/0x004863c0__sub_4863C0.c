// f1c  0x004863c0  size=50
int __thiscall sub_4863C0(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax
  int v4; // ecx

  v2 = a2;
  result = 0;
  if ( a2 >= 0 )
  {
    v4 = this[36];
    if ( v4 )
    {
      result = v4;
      if ( a2 > 0 )
      {
        do
        {
          if ( !result )
            break;
          result = *(_DWORD *)(result + 140);
          --v2;
        }
        while ( v2 > 0 );
      }
    }
  }
  return result;
}
