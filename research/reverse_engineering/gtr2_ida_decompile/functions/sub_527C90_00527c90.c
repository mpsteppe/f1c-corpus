int __thiscall sub_527C90(_DWORD *this, float a2)
{
  float *v3; // ecx
  char *v4; // esi
  int result; // eax
  int v6; // [esp+0h] [ebp-8h]
  int v7; // [esp+0h] [ebp-8h]

  if ( *this == 2 )
  {
    *(_BYTE *)(this[6] + 2892960) = 1;
    v3 = (float *)this[6];
    *(float *)&v6 = a2 + v3[723211];
    sub_522980(v3, v6);
    *(_DWORD *)(this[6] + 2892972) = 6;
    v4 = (char *)&unk_9204A0 + 22616 * *(_DWORD *)(this[6] + 2892924);
    sub_53F190(v4, 1, v7);
    result = dword_91E084;
    *((_DWORD *)v4 + 4821) = *(_DWORD *)(dword_91E084 + 19284);
    *((_DWORD *)v4 + 4822) = 0;
  }
  return result;
}
