int __thiscall sub_5F2A60(float *this, int a2)
{
  int result; // eax
  int v4; // edi
  float *v5; // ebx

  result = *((_DWORD *)this + 2387);
  if ( result )
  {
    *((_DWORD *)this + 1214) = a2;
    result = *((_DWORD *)this + 1206);
    v4 = 0;
    if ( result > 0 )
    {
      v5 = this + 762;
      do
      {
        if ( *v5 != this[1214] )
        {
          *v5 = this[1214];
          *((_DWORD *)this + 2) = (*(int (__stdcall **)(_DWORD, int, int, _DWORD))(**((_DWORD **)this + 2387) + 276))(
                                    *((_DWORD *)this + 2387),
                                    v4,
                                    8,
                                    *((_DWORD *)this + 1214));
        }
        result = *((_DWORD *)this + 1206);
        ++v4;
        v5 += 62;
      }
      while ( v4 < result );
    }
  }
  return result;
}
