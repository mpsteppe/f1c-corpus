int __thiscall sub_58C1F0(float *this, int a2, unsigned int a3)
{
  int result; // eax
  int v5; // [esp+Ch] [ebp-41Ch] BYREF
  _BYTE v6[512]; // [esp+10h] [ebp-418h] BYREF
  int v7; // [esp+210h] [ebp-218h]
  char v8; // [esp+214h] [ebp-214h]
  int v9; // [esp+21Ch] [ebp-20Ch]
  int v10; // [esp+220h] [ebp-208h]
  int v11; // [esp+224h] [ebp-204h]
  _BYTE v12[512]; // [esp+228h] [ebp-200h] BYREF

  result = 0;
  memset(v12, 0, sizeof(v12));
  v7 = 0;
  v11 = 0;
  v9 = 0;
  v10 = 0;
  v8 = 1;
  if ( a3 <= 4 )
  {
    for ( result = (*(int (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 36))(a2, v12, 512);
          result;
          result = (*(int (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 36))(a2, v12, 512) )
    {
      result = sub_612EB0(v6);
      if ( result )
      {
        if ( result == 2 )
          return result;
      }
      else
      {
        if ( sub_6134B0("MinimumRPM", (int)&v5, 0, 0, 0, 0, 0, 0, 0) )
          this[4 * a3 + 1] = *(float *)&v5 * 0.1047197551196598;
        if ( sub_6134B0("MaximumRPM", (int)&v5, 0, 0, 0, 0, 0, 0, 0) )
          this[4 * a3 + 2] = *(float *)&v5 * 0.1047197551196598;
        if ( sub_6134B0("NaturalRPM", (int)&v5, 0, 0, 0, 0, 0, 0, 0) )
        {
          if ( *(float *)&v5 > 0.0 )
            this[4 * a3 + 4] = 1.0 / (*(float *)&v5 * 0.1047197551196598);
          else
            this[4 * a3 + 4] = 0.0;
        }
      }
    }
  }
  return result;
}
