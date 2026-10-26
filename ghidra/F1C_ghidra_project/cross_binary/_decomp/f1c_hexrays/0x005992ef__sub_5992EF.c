// f1c  0x005992ef  size=89
// positive sp value has been detected, the output may be wrong!
_DWORD *__thiscall sub_5992EF(_DWORD *this, int a2, unsigned __int8 a3)
{
  char *v4; // edi
  int v5; // eax
  int v7; // [esp-4h] [ebp-10h]
  char *retaddr; // [esp+Ch] [ebp+0h]

  if ( -1 - this[2] <= (unsigned int)retaddr )
    sub_59AD49(v7);
  if ( retaddr )
  {
    v4 = &retaddr[this[2]];
    if ( (unsigned __int8)sub_599560(v4, 0) )
    {
      sub_58BB10((unsigned __int8 *)(this[2] + this[1]), a3, (unsigned int)retaddr);
      v5 = this[1];
      this[2] = v4;
      v4[v5] = 0;
    }
  }
  return this;
}
