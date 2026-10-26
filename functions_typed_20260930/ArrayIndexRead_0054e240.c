int __thiscall sub_54E240(_DWORD *this, int a2)
{
  if ( a2 >= this[72] )
    return 0;
  else
    return *(_DWORD *)(*(_DWORD *)(this[73] + 36 * a2 + 8) + 4);
}

