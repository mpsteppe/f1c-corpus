int __stdcall sub_48A490(int a1)
{
  int result; // eax
  int v2; // esi
  int *v3; // edi
  int v4; // edx
  unsigned __int8 v5; // bl
  int v6; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  v2 = -1;
  if ( result )
  {
    v3 = *(int **)(result + 28);
    if ( v3 )
    {
      v4 = *v3;
      v6 = 1;
      v7 = 0;
      result = (*(int (__thiscall **)(int *, int *, int *))(v4 + 76))(v3, &v6, &v7);
      if ( !(_BYTE)result || v6 == -1 )
      {
        v5 = 0;
        while ( 1 )
        {
          result = (*(int (__thiscall **)(int *, _DWORD))(*v3 + 92))(v3, v5);
          if ( (unsigned __int8)result < 5u )
            break;
          if ( ++v5 >= 4u )
          {
            dword_600F50 = -1;
            return result;
          }
        }
        v2 = dword_600F50;
        do
        {
          if ( a1 == 1 )
            ++v2;
          else
            --v2;
          if ( v2 >= 0 )
          {
            if ( v2 > 3 )
              v2 = 0;
          }
          else
          {
            v2 = 3;
          }
          result = (*(int (__thiscall **)(int *, int))(*v3 + 92))(v3, v2);
        }
        while ( (unsigned __int8)result >= 5u );
      }
    }
  }
  dword_600F50 = v2;
  return result;
}
