int __thiscall sub_5AB000(char *this, int a2)
{
  _DWORD *v2; // ebx
  int v4; // edi
  _DWORD *v5; // ebp
  int v6; // eax

  v2 = *(_DWORD **)(a2 + 16);
  if ( v2[6] )
  {
    v4 = 0;
    if ( *((int *)this + 1284) > 0 )
    {
      v5 = this + 4568;
      do
      {
        *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int *))(**((_DWORD **)this + 1112) + 240))(
                            *((_DWORD *)this + 1112),
                            v4,
                            &a2);
        v6 = a2;
        if ( a2 )
        {
          if ( v2[6] == a2 )
          {
            sub_5AA7A0(v5, 0);
            v6 = a2;
          }
          *(_DWORD *)this = (*(int (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
        }
        ++v4;
        v5 += 17;
      }
      while ( v4 < *((_DWORD *)this + 1284) );
    }
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v2[6] + 8))(v2[6]);
    v2[6] = 0;
  }
  v2[14] &= 0xFFFFFBF7;
  v2[15] = 0;
  return 0;
}
