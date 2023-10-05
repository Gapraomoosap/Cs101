import logo from './logo.svg';
import './App.css';
import Bisection from './componant/Bisection';

function App() {
  return (
    <div className="App">
      <Bisection />
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
      </header>
    </div>
  );
}

export default App;
