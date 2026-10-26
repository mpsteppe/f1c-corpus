int __thiscall sub_554D70(char *this, int a2)
{
  _DWORD *v2; // ebp
  int v4; // edi
  _DWORD *v5; // ebx
  int v6; // eax

  v2 = *(_DWORD **)(a2 + 84);
  if ( v2[5] )
  {
    v4 = 0;
    if ( *((int *)this + 1260) > 0 )
    {
      v5 = this + 4472;
      do
      {
        *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int *))(**((_DWORD **)this + 1088) + 240))(
                            *((_DWORD *)this + 1088),
                            v4,
                            &a2);
        v6 = a2;
        if ( a2 )
        {
          if ( v2[5] == a2 )
          {
            StateParameterSetterWithVirtualDeviceNotify(v5, 0);
            v6 = a2;
          }
          (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
        }
        ++v4;
        v5 += 17;
      }
      while ( v4 < *((_DWORD *)this + 1260) );
    }
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v2[5] + 8))(v2[5]);
    v2[5] = 0;
  }
  v2[6] &= 0xFFFFFBF7;
  v2[14] = -1082130432;
  return 0;
}

