void __thiscall sub_411100(_DWORD *this)
{
  int v1; // [esp+0h] [ebp-20h]
  float v2; // [esp+4h] [ebp-1Ch]
  int v3; // [esp+10h] [ebp-10h]
  float v4; // [esp+14h] [ebp-Ch]
  float v5; // [esp+18h] [ebp-8h] BYREF
  float v6; // [esp+1Ch] [ebp-4h] BYREF

  if ( !this[2] )
    return;
  v2 = flt_B70EAC * 0.01745433;
  *(float *)&v1 = flt_B70E88 * 0.01745433;
  sub_5E5240(v1, v2, 0);
  sub_5E5190(dword_B70E64 != 0);
  sub_5E4DF0(sub_410EA0, 0);
  v3 = 1140457472;
  v4 = 0.40000001;
  if ( !dword_B71758 )
  {
    v3 = 1132068864;
    v4 = 0.30000001;
    goto LABEL_8;
  }
  if ( dword_B71758 == 2 )
  {
    v4 = 0.5;
    sub_5E54E0(1056964608, 1144750080);
    goto LABEL_9;
  }
  if ( dword_B71758 != 3 )
  {
LABEL_8:
    sub_5E54E0(1056964608, v3);
    goto LABEL_9;
  }
  v4 = 0.60000002;
  sub_5E54E0(1056964608, 1148846080);
LABEL_9:
  sub_5E4F30(v4);
  sub_5E5650(dword_B70F9C != 0);
  v6 = 1.0;
  v5 = 150.0;
  sub_5E4DD0(&v6, &v5);
  if ( flt_B70F54 > 0.0 )
    v6 = flt_B70F54;
  if ( flt_B70F78 > 0.0 )
    v5 = flt_B70F78;
  sub_5E54E0(LODWORD(v6), LODWORD(v5));
}
