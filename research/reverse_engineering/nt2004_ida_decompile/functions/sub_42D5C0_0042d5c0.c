void __thiscall sub_42D5C0(int this, int a2)
{
  double v3; // st7
  int v4; // eax
  double v5; // st7
  float v6; // [esp+0h] [ebp-10h]
  float v7; // [esp+0h] [ebp-10h]
  float v8; // [esp+0h] [ebp-10h]
  float v9; // [esp+0h] [ebp-10h]

  if ( *(float *)(this + 24740) < 0.0 )
  {
    *(_DWORD *)(this + 24740) = 1065353216;
    if ( *(float *)(a2 + 8) <= 0.1 )
    {
      if ( *(float *)(a2 + 8) < -0.1 )
      {
        v4 = *(_DWORD *)(this + 24756);
        if ( v4 <= 0 )
          *(_DWORD *)(this + 24296) = -1082130432;
        else
          *(_DWORD *)(this + 24756) = v4 - 1;
        *(_DWORD *)(this + 24748) = 3;
        v5 = *(float *)(this + 17932);
        *(float *)(this + 24744) = *(float *)(this + 17932);
        v8 = v5 * 0.94999999;
        sub_51BF90(LODWORD(v8), 0);
        v9 = *(float *)(this + 24744) * 0.94999999;
        sub_51BF90(LODWORD(v9), 1);
      }
    }
    else
    {
      if ( *(float *)(this + 24760) > (double)*(float *)(this + 23852) )
        sub_42C150(this, 8, 1000593162, 0.0);
      *(_DWORD *)(this + 24748) = 12;
      v3 = *(float *)(this + 18428);
      *(float *)(this + 24744) = *(float *)(this + 18428);
      v6 = v3 * 0.92500001;
      sub_51BF90(LODWORD(v6), 2);
      v7 = *(float *)(this + 24744) * 0.92500001;
      sub_51BF90(LODWORD(v7), 3);
    }
  }
}
