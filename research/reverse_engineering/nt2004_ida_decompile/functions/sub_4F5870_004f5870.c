int __thiscall sub_4F5870(int this, char *String, int a3)
{
  _DWORD *v4; // edi
  int v5; // eax
  int result; // eax
  char *v7; // edx
  char v8; // al
  char *v9; // eax
  char v10; // cl
  char *v11; // eax
  char v12; // cl
  int v13; // [esp+Ch] [ebp-104h] BYREF
  char String1; // [esp+10h] [ebp-100h] BYREF
  char v15; // [esp+11h] [ebp-FFh] BYREF

  if ( sub_577ED0(String, aLegal, &String1, 0) && !_strcmpi(&String1, aTrue) )
    *(_BYTE *)(this + 92) = 1;
  v4 = (_DWORD *)(this + 8);
  *(float *)&v13 = 0.0;
  if ( sub_4F5760(String, off_611838, (float *)(this + 8), a3) )
    *(_DWORD *)(this + 12) = *v4;
  if ( sub_4F5760(String, off_611834, (float *)&v13, a3) )
    *(float *)(this + 12) = *(float *)v4 - *(float *)&v13;
  sub_4F5760(String, aResistance, (float *)(this + 16), a3);
  if ( sub_4F5760(String, aBumpamp, (float *)(this + 20), a3) )
    *(float *)(this + 20) = *(float *)(this + 20) * 0.25;
  if ( sub_4F5760(String, aBumpwavelen, (float *)&v13, a3) )
  {
    if ( *(float *)&v13 < 3.0 )
      *(float *)&v13 = 3.0;
    *(float *)(this + 24) = 6.283185307179586 / *(float *)&v13;
  }
  sub_4F5760(String, aSpring_0, (float *)(this + 28), a3);
  sub_4F5760(String, aDamper, (float *)(this + 32), a3);
  sub_4F5760(String, aCollfrict, (float *)(this + 36), a3);
  sub_577FA0(aSparks, this + 40, 0, 0, 0);
  sub_577FA0(aScraping, this + 41, 0, 0, 0);
  sub_577FA0(aWallskids, this + 42, 0, 0, 0);
  if ( sub_4F5760(String, aSink, (float *)&v13, a3) )
    *(double *)(this + 96) = *(float *)&v13;
  if ( sub_577ED0(String, aSound_1, &String1, 0) )
  {
    if ( !strcmp(&String1, off_611838) )
    {
      *(_DWORD *)(this + 44) = 6;
      *(_DWORD *)(this + 48) = 22;
      *(_DWORD *)(this + 52) = 28;
      goto LABEL_35;
    }
    if ( !strcmp(&String1, off_611834) )
    {
      *(_DWORD *)(this + 44) = 7;
      *(_DWORD *)(this + 48) = 23;
      *(_DWORD *)(this + 52) = 28;
      goto LABEL_35;
    }
    if ( !strcmp(&String1, aDirt) )
    {
      *(_DWORD *)(this + 44) = 9;
      *(_DWORD *)(this + 48) = 25;
      *(_DWORD *)(this + 52) = 33;
      goto LABEL_35;
    }
    if ( !strcmp(&String1, aGrass) )
    {
      *(_DWORD *)(this + 44) = 8;
      *(_DWORD *)(this + 48) = 24;
      *(_DWORD *)(this + 52) = 33;
      goto LABEL_35;
    }
    if ( !strcmp(&String1, aGravel) )
    {
      *(_DWORD *)(this + 44) = 10;
      *(_DWORD *)(this + 48) = 26;
      *(_DWORD *)(this + 52) = 33;
      goto LABEL_35;
    }
    if ( !strcmp(&String1, aRumble) )
    {
      *(_DWORD *)(this + 44) = 11;
      *(_DWORD *)(this + 48) = 22;
      *(_DWORD *)(this + 52) = 28;
      goto LABEL_35;
    }
    if ( !strcmp(&String1, aTirewall) )
    {
      v5 = 33;
LABEL_34:
      *(_DWORD *)(this + 44) = v5;
      *(_DWORD *)(this + 48) = v5;
      *(_DWORD *)(this + 52) = v5;
      goto LABEL_35;
    }
    if ( !strcmp(&String1, aSolidwall) || !strcmp(&String1, aGuardrail) )
    {
      v5 = 28;
      goto LABEL_34;
    }
  }
LABEL_35:
  result = sub_577E50(String, aMaterials, (int)&String1);
  if ( result )
  {
    _strupr(&String1);
    if ( String1 )
    {
      v7 = &v15;
      do
      {
        v8 = *(v7 - 1);
        if ( v8 == 32 )
        {
          v9 = v7;
          do
          {
            v10 = *v9;
            *(v9 - 1) = *v9;
            ++v9;
          }
          while ( v10 );
        }
        else if ( v8 == 44 && (*v7 == 44 || !*v7) )
        {
          v11 = v7;
          do
          {
            v12 = *v11;
            *(v11 - 1) = *v11;
            ++v11;
          }
          while ( v12 );
        }
        else
        {
          ++v7;
        }
      }
      while ( *(v7 - 1) );
    }
    return sub_578600(&String1);
  }
  return result;
}
