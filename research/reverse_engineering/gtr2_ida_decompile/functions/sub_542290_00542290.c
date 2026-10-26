int __usercall sub_542290@<eax>(const char *a1@<eax>)
{
  int result; // eax
  int v4; // esi
  int v5; // ebx
  int v6; // ecx
  char *v7; // edi
  char v8; // dl
  int v9; // edx
  int v10; // edx

  result = 0;
  v4 = strlen(a1);
  v5 = 0;
  if ( v4 > 0 )
  {
    v6 = 0;
    v7 = (char *)&a1[v4 - 1];
    do
    {
      v8 = *v7;
      if ( *v7 < 97 || v8 > 102 )
      {
        if ( v8 < 65 || v8 > 70 )
        {
          if ( v8 < 48 || v8 > 57 )
            return result;
          v9 = v8 - 48;
        }
        else
        {
          v9 = v8 - 55;
        }
      }
      else
      {
        v9 = v8 - 87;
      }
      v10 = v9 << v6;
      v6 += 4;
      result += v10;
      ++v5;
      --v7;
    }
    while ( v5 < v4 );
  }
  return result;
}
