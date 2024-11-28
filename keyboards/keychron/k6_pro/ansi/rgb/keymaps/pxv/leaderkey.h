/****************************************************************************************************
*  section == leader key sequences
****************************************************************************************************/
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_LEAD) {             // LEAD LEAD = CAPS  (a bit slow to activate)
      tap_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_QUOT) {             // with the following seq, helps check active layout.
      SEND_STRING("Dvorak");
    }
    SEQ_ONE_KEY(KC_Q) {                // with the preceding, helps check active layout.
      SEND_STRING("Querty");
    }
    SEQ_ONE_KEY(KC_D) {                // year and month
      SEND_STRING("2023-09-");
    }
    SEQ_ONE_KEY(KC_R) {                // Regards, \nPeter
      SEND_STRING("Regards,\nPeter");
    }
    SEQ_ONE_KEY(KC_LBRC) {             // mostly intended to indent markdown bullets
      tap_code16(G(KC_LEFT));
      tap_code(KC_DEL);
      tap_code16(G(KC_RIGHT));
    }
    SEQ_ONE_KEY(KC_T) {                // Insert markdown for "todo" 
      SEND_STRING("- [ ] ");
    }
    //SEQ_ONE_KEY(KC_SPACE) {            // 
      //SEND_STRING("- [ ] ");
    //}
    SEQ_ONE_KEY(KC_J) {                // Invoke Alfred with jj keyword
      tap_code16(G(KC_SPC));
      SEND_STRING(SS_DELAY(200));
      SEND_STRING("jj ");
    }
    SEQ_ONE_KEY(KC_L) {                // Invoke Alfred with link keyword
      tap_code16(G(KC_SPC));
      SEND_STRING(SS_DELAY(200));
      SEND_STRING("link ");
    }
    SEQ_ONE_KEY(KC_H) {                // Invoke Hook with CTRL-t
      tap_code16(C(KC_H));
      SEND_STRING(SS_DELAY(300));
      tap_code16(C(KC_T));
    }
    SEQ_ONE_KEY(KC_O) {                // Invoke Hook with LGUI-N, currently mapped to Omnifocus
        tap_code16(C(KC_H));
        SEND_STRING(SS_DELAY(400));
        tap_code16(G(KC_N));
        SEND_STRING(SS_DELAY(400));
        tap_code16(G(KC_TAB));
    }
    SEQ_TWO_KEYS(KC_O, KC_E) {         // Invoke Hook for Omnifocus from DT3

        register_code(KC_LSFT);
        register_code(KC_LGUI);
        tap_code16(KC_LEFT);
        tap_code16(KC_RIGHT);
        unregister_code(KC_LSFT);
        unregister_code(KC_LGUI);

        tap_code16(C(KC_H));
        SEND_STRING(SS_DELAY(200));

        // -----> Select the ctl-q option (copy selection and link)
        tap_code16(C(KC_T));
        SEND_STRING(SS_DELAY(100));
        tap_code16(C(KC_Q));
        SEND_STRING(SS_DELAY(100));

        // -----> Invoke Hook 
        //tap_code16(C(KC_H));
        //SEND_STRING(SS_DELAY(100));

        // -----> Select the command option for omnifocus
        tap_code16(G(KC_N));
        SEND_STRING(SS_DELAY(500));

        // -----> tab into the new item, left arrow, space, paste
        tap_code(KC_TAB);
        SEND_STRING(SS_DELAY(400));
        tap_code(KC_TAB);
        SEND_STRING(SS_DELAY(400));
        tap_code16(G(KC_V));
        SEND_STRING(SS_DELAY(500));

        // -----> Invoke Hook 
        tap_code16(C(KC_H));
        SEND_STRING(SS_DELAY(200));

        // -----> Copy Link
        tap_code16(G(KC_C));
        SEND_STRING(SS_DELAY(100));

        // -----> return to previous app
        tap_code16(G(KC_TAB));
        SEND_STRING(SS_DELAY(400));

        // -----> insert todo and OF link markup
        tap_code(KC_RIGHT);
        SEND_STRING("](");
        SEND_STRING(SS_DELAY(200));
      tap_code16(G(KC_V));
      SEND_STRING(")");
      tap_code16(G(KC_LEFT));
      SEND_STRING("- [ ] [");
      tap_code16(G(KC_RIGHT));
    }
    SEQ_TWO_KEYS(KC_X, KC_X) {         //:q!
      tap_code(KC_ESC);
      SEND_STRING(":q!");
    }
    SEQ_TWO_KEYS(KC_Y, KC_Y) {         //:wq
      tap_code(KC_ESC);
      SEND_STRING(":wq");
    }
    SEQ_TWO_KEYS(KC_P, KC_V) {         // Peter Vassilatos
      SEND_STRING("Peter Vassilatos");
    }
    SEQ_TWO_KEYS(KC_U, KC_D) {         // uvicorn main:app --port 51220 --reload
      SEND_STRING("uvicorn main:app --port 51220 --reload");
    }
    SEQ_TWO_KEYS(KC_U, KC_P) {         // uvicorn main:app --host 0.0.0.0 --port 51220 --reload
      SEND_STRING("uvicorn main:app --host 0.0.0.0 --port 51220 --reload");
    }
    SEQ_TWO_KEYS(KC_U, KC_C) {         // uchicago
      SEND_STRING("uchicago");
    }
    SEQ_THREE_KEYS(KC_U, KC_P, KC_C) { // UChicago
      SEND_STRING("UChicago");
    }
    SEQ_TWO_KEYS(KC_M, KC_I) { // MIDRC
      SEND_STRING("MIDRC");
    }
    SEQ_TWO_KEYS(KC_C, KC_H) { // CHoRUS
       SEND_STRING("CHoRUS");
    }
    //SEQ_FOUR_KEYS(KC_P, KC_C, KC_H, KC_O) { // CHoRUS
    //  SEND_STRING("CHoRUS");
    //}
    //SEQ_FOUR_KEYS(KC_P, KC_C, KC_H, KC_O) { // CHoRUS
    //  SEND_STRING("CHoRUS");
    //}
    //SEQ_FOUR_KEYS(KC_P, KC_C, KC_H, KC_O) { // CHoRUS
    //  SEND_STRING("CHoRUS");
    //}
  }
}

