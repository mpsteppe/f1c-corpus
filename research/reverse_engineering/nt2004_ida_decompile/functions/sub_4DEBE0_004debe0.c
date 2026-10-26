void __thiscall sub_4DEBE0(int this, float a2)
{
  char *v3; // eax
  int v4; // ecx
  double v5; // st7
  long double v6; // st6
  int v7; // ecx
  float v8; // [esp+8h] [ebp-4h]

  if ( *(float *)(this + 232) + 1.5 <= a2 )
  {
    v3 = (char *)&unk_62BF68 + 25304 * *(_DWORD *)(this + 228);
    *(_DWORD *)(this + 228) = -1;
    v4 = *((_DWORD *)v3 + 4146);
    if ( v4 == 1 || v4 == 2 )
    {
      v5 = *(float *)(this + 240) - sub_51C630(v3 + 84);
      if ( v5 >= 0.0 )
      {
        if ( v5 > 0.69999999 )
          v5 = 0.69999999;
      }
      else
      {
        v5 = 0.0;
      }
      v6 = 1.0;
      if ( *(float *)(this + 244) > 0.0 )
        v6 = 1.0 - sqrt(*(float *)(this + 244));
      v8 = v6 * v5 + *(float *)(this + 236);
      if ( v8 > (double)*(float *)&dword_7671CC )
      {
        v7 = *(_DWORD *)(this + 216);
        if ( v7 < 2 )
        {
          if ( dword_75CBB0 == 7 && (*(float *)&dword_7671CC + *(float *)&dword_7671CC < v8 || v7 > 0) )
          {
            sub_4DC690((int *)this, aDangerousDrivi, 1, 10);
            sub_41B4E0(aDangerousDrivi);
          }
          else
          {
            sub_4DC580((void *)this, aDangerousDrivi);
          }
        }
        else
        {
          sub_4DCCC0((int *)this, aDangerousDrivi);
        }
        ++*(_DWORD *)(this + 216);
        *(float *)(this + 220) = a2;
      }
    }
  }
}
