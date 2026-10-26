int __thiscall sub_4B9B80(float **this, float a2)
{
  int *v2; // edx
  double v3; // st7
  int v4; // eax
  double v5; // st7
  int v6; // esi
  int result; // eax
  int v8; // edi
  int i; // esi
  float v10; // [esp+10h] [ebp-Ch]
  float v11; // [esp+14h] [ebp-8h]
  char v12; // [esp+18h] [ebp-4h]

  v2 = (int *)this;
  if ( a2 == -9.9999997e37 )
    a2 = FloatGetter(*this);
  v10 = *(float *)(*v2 + 3900);
  v11 = a2;
  v12 = 1;
  if ( a2 < (double)v10 )
  {
    v11 = *(float *)(*v2 + 3900);
    v10 = a2;
    v12 = 0;
  }
  TimedAudioEventPlayback(*v2, v10, v11, v12);
  BufferReset((char **)&dword_83EE60);
  v3 = v10 * 40.0;
  sub_5895A2(v3);
  v4 = CRTFtol(v3);
  v5 = v11 * 40.0;
  v6 = v4;
  sub_5895A2(v5);
  result = CRTFtol(v5);
  if ( v6 != result )
  {
    v8 = dword_5C329C;
    for ( i = 0; i < v8; ++i )
    {
      sub_4EE2D0(dword_7C54F0[i] + 12);
      result = MultiObjectRemove(a2);
    }
  }
  return result;
}
