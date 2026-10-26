BOOL __thiscall sub_67F481(int this, int a2)
{
  int v3; // eax
  BOOL result; // eax

  result = 0;
  if ( sub_67EC87((_DWORD *)this, a2) )
  {
    if ( *(_DWORD *)(this + 16) == *(_DWORD *)(a2 + 16)
      && *(_DWORD *)(this + 20) == *(_DWORD *)(a2 + 20)
      && *(_DWORD *)(this + 24) == *(_DWORD *)(a2 + 24)
      && *(_DWORD *)(this + 28) == *(_DWORD *)(a2 + 28)
      && *(_DWORD *)(this + 52) == *(_DWORD *)(a2 + 52) )
    {
      if ( sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 32), *(_DWORD *)(a2 + 32)) )
      {
        if ( sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 36), *(_DWORD *)(a2 + 36)) )
        {
          if ( sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 40), *(_DWORD *)(a2 + 40)) )
          {
            if ( sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 44), *(_DWORD *)(a2 + 44)) )
            {
              if ( sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 48), *(_DWORD *)(a2 + 48)) )
              {
                v3 = *(_DWORD *)(this + 52);
                if ( !v3 || !memcmp(*(const void **)(this + 56), *(const void **)(a2 + 56), 4 * v3) )
                  return 1;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
