char __thiscall sub_475980(void *this)
{
  int v1; // eax
  int v2; // esi
  int v3; // ecx
  int v4; // esi
  int v5; // edx

  v1 = sub_4A50D0(this);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 84);
    if ( v2 )
    {
      sub_4E8C80(v2 + 260);
      sub_4E8A30(&byte_7D6A30);
      LOBYTE(v1) = *(_BYTE *)(v2 + 392);
      if ( !(_BYTE)v1 )
      {
        v1 = 36 * *(_DWORD *)dword_7689CC;
        if ( dword_767454[9 * *(_DWORD *)dword_7689CC] == 4 )
        {
          v3 = dword_76745C[9 * *(_DWORD *)dword_7689CC];
          v4 = dword_767460[9 * *(_DWORD *)dword_7689CC];
          dword_767454[9 * *(_DWORD *)dword_7689CC] = 0;
          v5 = *(int *)((char *)dword_767454 + v1);
          if ( v5 >= v3 )
          {
            if ( v5 > v4 )
              *(int *)((char *)dword_767454 + v1) = v4;
          }
          else
          {
            *(int *)((char *)dword_767454 + v1) = v3;
          }
        }
      }
    }
  }
  return v1;
}
