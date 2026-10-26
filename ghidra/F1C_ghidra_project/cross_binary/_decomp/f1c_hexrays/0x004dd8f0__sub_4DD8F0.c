// f1c  0x004dd8f0  size=247
double __thiscall sub_4DD8F0(void *this)
{
  int v2; // ebp
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  int i; // esi
  float *v8; // eax
  double v9; // st4
  int v11; // [esp+18h] [ebp-10h]
  int v12; // [esp+1Ch] [ebp-Ch]
  double v13; // [esp+20h] [ebp-8h]

  v11 = sub_4DD4E0(this);
  v13 = -1.797693134862316e308;
  v2 = 0;
  v12 = sub_54C210(this);
  if ( v12 > 0 )
  {
    do
    {
      v3 = sub_54C230(v2);
      if ( *(float *)(v3 + 244) == 0.0 )
      {
        v4 = *(_DWORD *)(v3 + 20);
        if ( (v4 & 0x2000000) != 0 )
          v5 = 2 - ((v4 & 0x40) != 0);
        else
          v5 = 4 - ((v4 & 0x40) != 0);
      }
      else
      {
        v5 = 0;
      }
      if ( v5 >= v11 )
      {
        v6 = sub_54E100(v3);
        for ( i = 0; i < v6; ++i )
        {
          v8 = (float *)sub_54E120(i);
          v9 = *v8 * *v8 + v8[1] * v8[1] + v8[2] * v8[2];
          if ( v9 > v13 )
            v13 = v9;
        }
      }
      ++v2;
    }
    while ( v2 < v12 );
  }
  return v13;
}
