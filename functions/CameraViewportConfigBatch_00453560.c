int __thiscall sub_453560(_DWORD *this)
{
  _BYTE *v2; // ecx
  _BYTE *v3; // ecx
  _BYTE *v4; // ecx
  _BYTE *v5; // ecx
  _BYTE *v6; // ecx
  _BYTE *v7; // ecx
  _BYTE *v8; // ecx
  _BYTE *v9; // ecx
  _BYTE *v10; // ecx
  _BYTE *v11; // ecx
  _BYTE *v12; // ecx
  _BYTE *v13; // ecx
  _BYTE *v14; // ecx
  _BYTE *v15; // ecx
  _BYTE *v16; // ecx
  _BYTE *v17; // ecx
  _BYTE *v18; // ecx
  _BYTE *v19; // ecx
  _BYTE *v20; // ecx
  _BYTE *v21; // ecx
  _BYTE *v22; // ecx
  _BYTE *v23; // ecx
  _BYTE *v24; // ecx
  _BYTE *v25; // ecx
  _BYTE *v26; // ecx
  _BYTE *v27; // ecx
  _BYTE *v28; // ecx
  _BYTE *v29; // ecx
  _BYTE *v30; // ecx
  _BYTE *v31; // ecx
  _BYTE *v32; // ecx
  _BYTE *v33; // ecx
  _BYTE *v34; // ecx
  _BYTE *v35; // ecx
  _BYTE *v36; // ecx
  _BYTE *v37; // ecx
  _BYTE *v38; // ecx
  _BYTE *v39; // ecx
  _BYTE *v40; // ecx
  _BYTE *v41; // ecx
  _BYTE *v42; // ecx
  _BYTE *v43; // ecx
  _BYTE *v44; // ecx
  _BYTE *v45; // ecx
  _BYTE *v46; // ecx
  _BYTE *v47; // ecx
  _BYTE *v48; // ecx
  _BYTE *v49; // ecx
  _BYTE *v50; // ecx
  _BYTE *v51; // ecx
  _BYTE *v52; // ecx
  _BYTE *v53; // ecx
  _BYTE *v54; // ecx
  _BYTE *v55; // ecx
  _BYTE *v56; // ecx
  _BYTE *v57; // ecx
  _DWORD *v58; // esi
  int v59; // edi
  int result; // eax

  CollisionNodePropertySetter(byte_7CA594, 29, 2);
  CollisionNodePropertySetter(v2, 157, 2);
  CollisionNodePropertySetter(v3, 56, 2);
  CollisionNodePropertySetter(v4, 42, 2);
  CollisionNodePropertySetter(v5, 54, 2);
  CollisionNodePropertySetter(v6, 210, 0);
  CollisionNodePropertySetter(v7, 199, 0);
  CollisionNodePropertySetter(v8, 201, 0);
  CollisionNodePropertySetter(v9, 211, 0);
  CollisionNodePropertySetter(v10, 207, 0);
  CollisionNodePropertySetter(v11, 209, 0);
  CollisionNodePropertySetter(v12, 13, 1);
  CollisionNodePropertySetter(v13, 12, 1);
  CollisionNodePropertySetter(v14, 197, 0);
  CollisionNodePropertySetter(v15, 57, 0);
  CollisionNodePropertySetter(v16, 74, 0);
  CollisionNodePropertySetter(v17, 78, 0);
  CollisionNodePropertySetter(v18, 181, 2);
  CollisionNodePropertySetter(v19, 55, 2);
  CollisionNodePropertySetter(v20, 26, 2);
  CollisionNodePropertySetter(v21, 27, 2);
  CollisionNodePropertySetter(v22, 2, 0);
  CollisionNodePropertySetter(v23, 3, 0);
  CollisionNodePropertySetter(v24, 4, 0);
  CollisionNodePropertySetter(v25, 5, 0);
  CollisionNodePropertySetter(v26, 6, 0);
  CollisionNodePropertySetter(v27, 7, 0);
  CollisionNodePropertySetter(v28, 8, 0);
  CollisionNodePropertySetter(v29, 9, 0);
  CollisionNodePropertySetter(v30, 10, 0);
  CollisionNodePropertySetter(v31, 11, 0);
  CollisionNodePropertySetter(v32, 79, 2);
  CollisionNodePropertySetter(v33, 80, 2);
  CollisionNodePropertySetter(v34, 81, 2);
  CollisionNodePropertySetter(v35, 75, 2);
  CollisionNodePropertySetter(v36, 76, 2);
  CollisionNodePropertySetter(v37, 77, 2);
  CollisionNodePropertySetter(v38, 71, 2);
  CollisionNodePropertySetter(v39, 72, 2);
  CollisionNodePropertySetter(v40, 73, 2);
  CollisionNodePropertySetter(v41, 59, 0);
  CollisionNodePropertySetter(v42, 60, 0);
  CollisionNodePropertySetter(v43, 61, 0);
  CollisionNodePropertySetter(v44, 62, 0);
  CollisionNodePropertySetter(v45, 63, 0);
  CollisionNodePropertySetter(v46, 64, 0);
  CollisionNodePropertySetter(v47, 65, 0);
  CollisionNodePropertySetter(v48, 66, 0);
  CollisionNodePropertySetter(v49, 67, 0);
  CollisionNodePropertySetter(v50, 68, 0);
  CollisionNodePropertySetter(v51, 87, 0);
  CollisionNodePropertySetter(v52, 88, 0);
  CollisionNodePropertySetter(v53, 14, 2);
  CollisionNodePropertySetter(v54, 200, 2);
  CollisionNodePropertySetter(v55, 208, 2);
  CollisionNodePropertySetter(v56, 203, 2);
  CollisionNodePropertySetter(v57, 205, 2);
  v58 = this + 1736;
  v59 = 44;
  do
  {
    result = ConditionalCollisionDispatch(v58);
    v58 += 11;
    --v59;
  }
  while ( v59 );
  return result;
}
