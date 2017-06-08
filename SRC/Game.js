//dimensions réelles de l'écran
var _width;
var _height;
//dimensions de base de notre jeu
var _virtualWidth=1080;
var _virtualHeight=1920;
//ratio permettant d'adapter à la résolution de l'écran
var _iRatio;


function getWidth(){
    return _width;
}
function getHeight(){
    return _height;
}

//fonction de démarrage du jeu
function start(width_,height_){
    if(width_> height_){
        _width=height_*(_virtualWidth/_virtualHeight);
    }else{
        _width=width_;
    }
    _height=_width*(_virtualHeight/_virtualWidth);
    _iRatio=_width/_virtualWidth;
    main.width=_width;
    main.height=_height;
    gotoSplashscreen();
}
//convertit une dimension à la taille de l'écran
function convert(size_){
    return size_*_iRatio;
}

function convert(size_) {
    return size_*_iRatio;
}

var _oPageScene;

function gotoSplashscreen() {
    main.launchPage('splashscreen');
}
function gotoMenu() {
    main.launchPage('menu');
}
function gotoScene() {
    main.launchPage('scene');
}
function gotoGameover() {
    main.launchPage('gameOver');
}

