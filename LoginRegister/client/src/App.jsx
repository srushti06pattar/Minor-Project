import './App.scss';
import Dashboard from './Components/Dashboard/Dashboard';
import Login from './Components/Login/Login';
import Register from './Components/Register/Register';

// Importing React Router DOM
import { createBrowserRouter, RouterProvider } from 'react-router-dom';

// Create the router with a route for '/'
const router = createBrowserRouter([
  {
    path: '/',
    element: <Login />, // Redirect or load a default component for root
  },
  {
    path: '/login',
    element: <Login />,
  },
  {
    path: '/register',
    element: <Register />,
  },
  {
    path: '/dashboard',
    element: <Dashboard />,
  },
  {
    path: '*',  // Catch-all route for undefined paths
    element: <div>404 - Page Not Found</div>,
  },
]);

function App() {
  return (
    <div>
      <RouterProvider router={router} />
    </div>
  );
}

export default App;
