int sub_4EC080()
{
  int v0; // eax
  int v1; // edi
  int v2; // esi
  bool v3; // bl
  bool v4; // cl
  int v5; // eax
  bool v7; // [esp+9h] [ebp-3h]
  bool v8; // [esp+Ah] [ebp-2h]
  bool v9; // [esp+Bh] [ebp-1h]

  sub_50FD00(4);
  dword_75B17C = 1;
  dword_BE1204 = dword_B71E40 != 0;
  sub_5363D0(&unk_B76270);
  byte_91E234 = 1;
  v0 = sub_532D20(&unk_B76270);
  v1 = v0;
  if ( v0 )
  {
    v2 = sub_530490(v0);
    v9 = sub_616840("SkipPractice1") != 0;
    v8 = sub_616840("SkipPractice2") != 0;
    v3 = sub_616840("SkipQualifying1") != 0;
    v7 = sub_616840("SkipQualifying2") != 0;
    v4 = sub_616840("SkipWarmup") != 0;
    switch ( v2 )
    {
      case 1:
        if ( v9 )
        {
          if ( v8 )
          {
            if ( v3 )
              goto LABEL_14;
            v2 = 3;
          }
          else
          {
            v2 = 2;
          }
        }
        break;
      case 2:
        if ( v8 )
        {
          if ( v3 )
          {
            if ( v7 )
              goto LABEL_18;
            v2 = 4;
          }
          else
          {
            v2 = 3;
          }
        }
        break;
      case 3:
        if ( v3 )
        {
LABEL_14:
          if ( v7 )
            v2 = v4 + 5;
          else
            v2 = 4;
        }
        break;
      case 4:
        if ( v3 )
LABEL_18:
          v2 = v4 + 5;
        break;
      case 5:
        if ( v4 )
          goto LABEL_20;
        break;
      default:
LABEL_20:
        v2 = 6;
        break;
    }
    sub_430F70(&dword_B640C0, v2);
    v5 = dword_B71F2C;
    dword_B71F24 = v2;
    if ( v2 < dword_B71F2C || (v5 = dword_B71F30, v2 > dword_B71F30) )
      dword_B71F24 = v5;
    *(_DWORD *)(v1 + 95740) = v2;
  }
  return 0;
}
