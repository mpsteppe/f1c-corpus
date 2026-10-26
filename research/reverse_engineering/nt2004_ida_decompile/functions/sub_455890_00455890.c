int __thiscall sub_455890(float *this)
{
  int result; // eax
  float *v3; // ebx
  int v4; // esi
  int v5; // edi
  float *v6; // esi
  float v7; // [esp+0h] [ebp-20h]
  int v8; // [esp+1Ch] [ebp-4h]

  result = *((_DWORD *)this + 866);
  v8 = 0;
  if ( result > 0 )
  {
    do
    {
      if ( v8 )
      {
        v3 = this + 1123;
        v4 = 1;
      }
      else
      {
        v3 = this + 868;
        v4 = 0;
      }
      v5 = 0;
      v6 = (float *)((char *)&unk_769E9C + 864 * v4);
      do
      {
        v7 = v6[9] + v6[9];
        sub_4521D0(v3, v5++, v7, *v6, v6[18]);
        v6 += 27;
      }
      while ( v5 < 8 );
      result = ++v8;
    }
    while ( v8 < *((_DWORD *)this + 866) );
  }
  return result;
}
