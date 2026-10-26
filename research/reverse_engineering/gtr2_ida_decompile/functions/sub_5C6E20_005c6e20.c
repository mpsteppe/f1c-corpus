int __thiscall sub_5C6E20(int this)
{
  int v2; // edi
  int result; // eax
  int v4; // ecx
  int v5; // [esp+0h] [ebp-10h]

  v2 = **(_DWORD **)(this + 4);
  sub_4F14D0(v5);
  *(_DWORD *)(this + 8) = sub_5A8CF0(*(void **)(this + 8), 4 * v2, 304, 16, 0);
  for ( result = 0; result < v2; ++result )
  {
    if ( !result || result == v2 - 1 )
    {
      *(float *)(*(_DWORD *)(this + 8) + 4 * result) = 0.0;
    }
    else
    {
      v4 = *(_DWORD *)(*(_DWORD *)(this + 4) + 8);
      *(float *)(*(_DWORD *)(this + 8) + 4 * result) = ((double)*(unsigned __int8 *)(v4 + 8 * result + 8) * 0.0039215689
                                                      - (double)*(unsigned __int8 *)(v4 + 8 * result) * 0.0039215689)
                                                     * 0.5
                                                     + ((double)*(unsigned __int8 *)(v4 + 8 * result) * 0.0039215689
                                                      - (double)*(unsigned __int8 *)(v4 + 8 * result - 8) * 0.0039215689)
                                                     * 0.5;
    }
  }
  return result;
}
