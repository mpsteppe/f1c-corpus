int __stdcall sub_4B3D70(char *a1, int a2)
{
  double v2; // st7
  int v3; // eax
  char v4; // cl
  float v6; // [esp+Ch] [ebp-14h]
  char Buffer[16]; // [esp+10h] [ebp-10h] BYREF

  v6 = *(float *)(dword_75AAC4 + 18792);
  v2 = *(float *)(dword_75AAC4 + 17408);
  if ( v2 <= 0.0 )
  {
    v3 = 0;
    do
    {
      v4 = byte_6094AC[v3];
      Buffer[v3++] = v4;
    }
    while ( v4 );
  }
  else
  {
    sprintf(Buffer, off_6094B0, (unsigned int)(__int64)(v2 * v6));
  }
  if ( dword_7689F0 == 1 )
    sprintf(a1, "%.1f%s", v6 * 0.26417205, Buffer);
  else
    sprintf(a1, "%d%s", (unsigned int)(__int64)(v6 + 0.5), Buffer);
  return 0;
}
